

#include "Server.h"
#include "../controllers/PingController.h"
#include "../config/Constants.h"
#include "../controllers/TracksController.h"
#include "../controllers/PlayController.h"
#include <spdlog/spdlog.h>

void event_handler(struct mg_connection *new_connection, int event, void *event_data) {
    Server *self = NULL;
    struct returnType* ret;
    switch (event) {
        case MG_EV_HTTP_REQUEST:
            spdlog::get("console")->info("Got new request");
            self = (Server *) new_connection->user_data;
            if (self != NULL) {
                self->handleRequest(new_connection, (http_message *) event_data);
            }
            break;
        case MG_EV_HTTP_PART_BEGIN:
        case MG_EV_HTTP_PART_DATA:
            mg_file_upload_handler(new_connection, event, event_data, TracksController::upload_fname);
            break;
        case MG_EV_HTTP_PART_END:
            self = (Server *) new_connection->user_data;
            ret = mg_file_upload_handler(new_connection, event, event_data, TracksController::upload_fname);
            if (self != NULL) {
                ((TracksController*)self->controllers.back())->post(ret->trackId, ret->filename);
            }
            free(ret);
            break;
        default:
            break;
    }
}

Server::Server(int port, std::string ip) : server(NULL), connection(NULL), port(port), localIp(ip), running(false) {
    // Initialize controllers
    PingController *pingController = new PingController();
    PlayController *playController = new PlayController();
    TracksController *tracksController = new TracksController();
    registerController(pingController);
    registerController(tracksController);
    registerController(playController);
}

Server::~Server() {
    if (!running) {
        for (Controller *controller : controllers) {
            delete controller;
        }
    }
    delete server;
}

void Server::start() {
    if (server == NULL) {
        server = new mg_mgr;
        mg_mgr_init(server, NULL);
        spdlog::get("console")->info("Starting server on port {}", port);
        connection = mg_bind(server, std::to_string(port).c_str(), event_handler);
        if (connection == NULL) {
            spdlog::get("console")->error("Failed to create connection (Port in use?)");
        }
        connection->user_data = this;
        mg_set_protocol_http_websocket(connection); // TODO: ???
        running = true;
        for (;;) {
            // TODO: Send to pooler thread?
            mg_mgr_poll(server, 1000);
        }
    }
}

void Server::stop() {
    if (running) {
        mg_mgr_free(server);
        running = false;
    }
}

void Server::dispatchRequest(Request &request) {
    Response *response = handleRequest(request);

    if (response != NULL) {
        request.writeResponse(response);
        delete response;
    }
}

/*void Server::handleRequest(mg_connection *connection, int event, void *event_data) {
    Request request(connection, event, event_data);
    dispatchRequest(request);
}*/

void Server::handleRequest(mg_connection *connection, http_message *message) {
    Request request(connection, message);
    dispatchRequest(request);
}

Response *Server::handleRequest(Request &request) {
    Response *response;
    Controller *handler = NULL;

    for (Controller *controller : controllers) {
        if (controller->handles(request.getHttpVerb(), request.getUrl())) handler = controller;
    }
    if (handler == NULL) {
        response = new JSONResponse();
        response->setCode(HTTP_NOT_FOUND);
        spdlog::get("console")->warn("Response from {0} {1} was {2}", request.getHttpVerb(), request.getUrl(),
                                     response->getCode());
    } else {
        response = handler->process(request);
    }

    if (response != NULL) {
        return response;
    }

    return NULL;
}

void Server::registerController(Controller *controller) {
    controllers.push_back(controller);
}

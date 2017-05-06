

#include "Server.h"
#include "../controllers/PingController.h"
#include "../config/Constants.h"
#include "../controllers/TracksController.h"
#include "../controllers/PlayController.h"
#include <spdlog/spdlog.h>

struct mg_str upload_fname(struct mg_connection *c, struct mg_str file_name) {
    // Return the same filename. Do not actually do this except in test!
    // fname is user-controlled and needs to be sanitized.
    std::string *final = new std::string("../music/" + std::string(file_name.p));
    return mg_mk_str(final->c_str());
}

void event_handler(struct mg_connection *new_connection, int event, void *event_data) {
    Server *self = NULL;
    switch (event) {
        case MG_EV_HTTP_REQUEST:
            self = (Server *) new_connection->user_data;
            if (self != NULL) {
                self->handleRequest(new_connection, (http_message *) event_data);
            }
            break;
        case MG_EV_HTTP_PART_BEGIN:
        case MG_EV_HTTP_PART_DATA:
        case MG_EV_HTTP_PART_END:
            mg_file_upload_handler(new_connection, event, event_data, upload_fname);
            break;
        default:
            break;
    }
}

Server::Server(int port, std::string ip) : server(NULL), connection(NULL), port(port), localIp(ip), running(false) {
    // Initialize controllers
    PingController *pingController = new PingController();
    TracksController *tracksController = new TracksController();
    PlayController *playController = new PlayController();
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

void Server::handleRequest(mg_connection *connection, http_message *message) {
    Request request(connection, message);

    Response *response = handleRequest(request);

    if (response != NULL) {
        request.writeResponse(response);
        delete response;
    }
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

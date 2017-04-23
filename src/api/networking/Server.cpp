

#include "Server.h"
#include "../controllers/PingController.h"
#include "../config/Constants.h"
#include "../controllers/TracksController.h"
#include <spdlog/spdlog.h>
static struct mg_serve_http_opts s_http_server_opts;

void event_handler(struct mg_connection *c, int ev, void *p) {
    if (ev == MG_EV_HTTP_REQUEST) {
        mg_serve_http(c, (struct http_message *) p, s_http_server_opts);
        Server *self = (Server *) c->user_data;
        if (self != NULL) {
            self->handleRequest(c, (http_message *) p);
        }
    } else if (ev == MG_EV_RECV) {
//        struct mbuf *io = &c->recv_mbuf;
//        mg_send(c, io->buf, io->len);
//        mbuf_remove(io, io->len);
//        c->flags |= MG_F_SEND_AND_CLOSE;
    }
}

Server::Server(int port) : server(NULL), connection(NULL), port(port), running(false) {
    // Initialize controllers
    PingController *pingController = new PingController();
    TracksController *tracksController = new TracksController();
    registerController(pingController);
    registerController(tracksController);
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
        // UDP trials
//        const char *port = "udp://1234";
//        mg_bind(server, port, event_handler);

        s_http_server_opts.document_root = "..";
        s_http_server_opts.enable_directory_listing = "yes";

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


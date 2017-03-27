

#include "Server.h"
#include "../controllers/PingController.h"
#include <spdlog/spdlog.h>

void event_handler(struct mg_connection *c, int ev, void *p) {
    if (ev == MG_EV_HTTP_REQUEST) {
        Server *self = (Server *) c->user_data;
        if (self != NULL) {
            self->handleRequest(c, (http_message *) p);
        }
    }
}

Server::Server(int port) : server(NULL), connection(NULL), port(port), running(false) {
    // Initialize controllers
    PingController *pingController = new PingController();
    registerController(pingController);
}

Server::~Server() {
    if (running) {
        mg_mgr_free(server);
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
        connection->user_data = this;
        if (connection == NULL) {
            spdlog::get("console")->error("Failed to create connection");
        }
        mg_set_protocol_http_websocket(connection);
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
    }
}

int Server::handleRequest(mg_connection *connection, http_message *message) {
    Request request(connection, message);

    Response *response = handleRequest(request);

    if (response == NULL) {
        return EXIT_SUCCESS;
    } else {
        request.writeResponse(response);
        delete response;
        return EXIT_FAILURE;
    }
}

Response *Server::handleRequest(Request &request) {
    Response *response;

    for (Controller *controller : controllers) {
        response = controller->process(request);

        if (response != NULL) {
            return response;
        }
    }

    return NULL;
}

void Server::registerController(Controller *controller) {
    controllers.push_back(controller);
}




#include "Server.h"
#include <spdlog/spdlog.h>

static void event_handler(struct mg_connection *c, int ev, void *p) {
    if (ev == MG_EV_HTTP_REQUEST) {
        struct http_message *hm = (struct http_message *) p;

        // We have received an HTTP request. Parsed request is contained in `hm`.
        // Send HTTP reply to the client which shows full original request.
        mg_send_head(c, 200, hm->message.len, "Content-Type: application/json");
        mg_printf(c, "%.*s", hm->message.len, hm->message.p);
    }
}

Server::Server(int port) : server(NULL), connection(NULL), port(port), running(false) {
}

Server::~Server() {
    if (running) {
        mg_mgr_free(server);
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
            spdlog::get("console")->error("Failed to create connection");
        }
        mg_set_protocol_http_websocket(connection);
        running = true;
        for(;;) {
            mg_mgr_poll(server, 1000);
        }
    }
}

void Server::stop() {
    if (running) {
        mg_mgr_free(server);
    }
}
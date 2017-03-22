

#include "Server.h"

Server::Server(int port) : server(NULL), port(port) {
}

Server::~Server() {

}

void Server::start() {
    if (server == NULL) {
        mg_create_server(server);
    }
}

void Server::stop() {
    mg_destroy_server(&server);
}

void Server::registerController(Controller *controller) {
    controllers.push_back(controller);
}

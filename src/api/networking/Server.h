

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

#include <vector>
#include "mongoose/mongoose.h"
#include "../controllers/Controller.h"

class Server {
public:
    Server(int port = 8080);

    virtual ~Server();

    void start();

    void stop();

private:
    mg_mgr *server;
    mg_connection *connection;
    int port;
    bool running;
    std::vector<Controller *> controllers;

    int handleRequest(mg_connection *connection, http_message *message);

    friend void event_handler(mg_connection *c, int ev, void *p);

    Response *handleRequest(Request &request);
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

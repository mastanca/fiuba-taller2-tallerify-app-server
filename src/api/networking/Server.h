

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

#include <vector>
#include "mongoose/mongoose.h"
#include "../controllers/Controller.h"

class Server {
public:
    Server(int port = 8000);

    virtual ~Server();

    void start();

    void stop();

    void registerController(Controller *controller);

private:
    mg_server *server;
    int port;
    std::vector<Controller *> controllers;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

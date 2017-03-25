

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

#include <vector>
#include "mongoose/mongoose.h"

#define SC_INTENAL_SERVER_ERROR 500
#define SC_OK 200

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
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

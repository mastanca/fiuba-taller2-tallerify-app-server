

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

#include <vector>
#include "mongoose/mongoose.h"
#include "../controllers/Controller.h"

/**
 * \file Server.h
 * Mongoose server wrapper
 */

class Server {
    //! Friend class for testing private methods
    friend class ServerTest;

public:
    /**
     * Server constructor
     * @param port server port, defaults to 8080
     * @param ip server local ip, defaults to 127.0.0.1
     */
    Server(int port = 8080, std::string ip = "127.0.0.1");

    /**
     * Server destroyer
     */
    virtual ~Server();

    /**
     * Starts the server
     */
    void start();

    /**
     * Stops the server, cleaning associated resources
     */
    void stop();

private:
    mg_mgr *server;
    mg_connection *connection;
    int port;
    std::string localIp;
    bool running;
    std::vector<Controller *> controllers;

    void handleRequest(mg_connection *connection, http_message *message);

    void handleRequest(mg_connection *connection, int event, void *event_data);

    friend void event_handler(mg_connection *new_connection, int event, void *event_data);

    Response *handleRequest(Request &request);

    void registerController(Controller *controller);

    void dispatchRequest(Request &request);

};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVER_H

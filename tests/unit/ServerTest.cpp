

#include "ServerTest.h"
#include "../../src/api/networking/Server.h"
#include "../../src/api/config/Constants.h"
#include "../../src/api/controllers/PingController.h"


void ServerTest::testControllersRegistrationOnCreation() {
    Server server;

    ASSERT_GE(server.controllers.size(), 1);
}

void ServerTest::testNotFound() {
    Server server;
    PingController controller;

    http_message message;
    std::string body = "hi";
    std::string method = HTTP_GET;
    std::string uri = "/what";
    message.body = mg_mk_str(body.c_str());
    message.method = mg_mk_str(method.c_str());
    message.uri = mg_mk_str(uri.c_str());
    mg_connection connection;

    Request *request = new Request(&connection, &message);

    ASSERT_EQ(server.handleRequest(*request)->getCode(), HTTP_NOT_FOUND);
    delete request;
}

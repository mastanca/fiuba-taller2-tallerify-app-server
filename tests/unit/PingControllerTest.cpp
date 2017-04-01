

#include "PingControllerTest.h"
#include "../../src/api/controllers/PingController.h"
#include "../../src/api/config/Constants.h"

void PingControllerTest::testRouteMapping() {
    PingController controller;

    ASSERT_TRUE(controller.handles(HTTP_GET, "/ping"));
}

void PingControllerTest::testGet() {
    PingController controller;
    JSONResponse *response = new JSONResponse();
    http_message message;
    std::string body = "";
    std::string method = HTTP_GET;
    std::string uri = "/ping";
    message.body = mg_mk_str(body.c_str());
    message.method = mg_mk_str(method.c_str());
    message.uri = mg_mk_str(uri.c_str());
    mg_connection connection;
    Request *request = new Request(&connection, &message);
    controller.get(*request, *response);

    ASSERT_EQ(response->getBody(), "{\"ping\":\"pong\"}\n");
    delete response;
    delete request;
}

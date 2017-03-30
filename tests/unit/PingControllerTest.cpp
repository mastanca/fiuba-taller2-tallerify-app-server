

#include "PingControllerTest.h"
#include "../../src/api/controllers/PingController.h"
#include "../../src/api/config/Constants.h"

void PingControllerTest::testRouteMapping() {
    PingController controller;

    ASSERT_TRUE(controller.handles(HTTP_GET, "/ping"));
}

//void PingControllerTest::testGet() {
//    PingController controller;
//    JSONResponse *response = new JSONResponse();
//    http_message message;
//    mg_connection connection;
//    Request *request = new Request(&connection, &message);
//    controller.get(*request, *response);
//
//    ASSERT_EQ(response->getBody(), "{\"ping\":\"pong\"}\n");
//    delete response;
//    delete request;
//}

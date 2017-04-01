

#include "ControllerTest.h"
#include "../../src/api/config/Constants.h"

void ControllerTest::testInternalServerError() {
    Controller controller;
    ASSERT_EQ(controller.serverInternalError("fail")->getCode(), HTTP_SERVER_ERROR);
}

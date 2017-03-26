

#include "JSONResponseTest.h"
#include "../../src/api/config/Constants.h"
#include "../Mocks.h"

JSONResponseTest::JSONResponseTest() {}

void JSONResponseTest::testBodyCreation() {
    JSONResponse response;
    response["ping"] = "pong";

    ASSERT_EQ(response.getBody(), "{\"ping\":\"pong\"}\n");
}

void JSONResponseTest::testCodeSetting() {
    JSONResponse response;
    response.setCode(HTTP_BAD_REQUEST);

    ASSERT_EQ(response.getCode(), HTTP_BAD_REQUEST);
}

//using ::testing::AtLeast;                     // #1
//
//TEST(PainterTest, CanDrawSomething) {
//MockTurtle turtle;                          // #2
//EXPECT_CALL(turtle, PenDown())              // #3
//.Times(AtLeast(1));
//
//Painter painter(&turtle);                   // #4
//
//EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
//}



#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLERTEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLERTEST_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/api/networking/JSONResponse.h"

class PingControllerTest : public testing::Test {
public:
    PingControllerTest() {}

    void TestBody() {}

    void testRouteMapping();

    //void testGet();

};

TEST_F(PingControllerTest, testRouteMapping
) {
    PingControllerTest tester;
    tester.

            testRouteMapping();

}

//TEST_F(PingControllerTest, testGet
//) {
//    PingControllerTest tester;
//    tester.
//
//            testGet();
//
//}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLERTEST_H

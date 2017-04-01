

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUESTTEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUESTTEST_H


#include <gtest/gtest.h>

class RequestTest : public testing::Test {
public:
    RequestTest() {}

    void TestBody() {}

    void testHttpInitialization();
};

TEST_F(RequestTest, testHttpInitialization
) {
    RequestTest tester;
    tester.

            testHttpInitialization();

}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUESTTEST_H

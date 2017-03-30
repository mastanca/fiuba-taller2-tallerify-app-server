

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSETEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSETEST_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/api/networking/JSONResponse.h"

class JSONResponseTest : public testing::Test {
public:
    JSONResponseTest();

    void TestBody() {}

    void testBodyCreation();

    void testCodeSetting();

    void testGetData();
};

TEST_F(JSONResponseTest, testBodyCreation
) {
    JSONResponseTest tester;
    tester.

            testBodyCreation();

}

TEST_F(JSONResponseTest, testCodeSetting
) {
    JSONResponseTest tester;
    tester.

            testCodeSetting();

}

TEST_F(JSONResponseTest, testGetData
) {
    JSONResponseTest tester;
    tester.

            testGetData();

}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSETEST_H

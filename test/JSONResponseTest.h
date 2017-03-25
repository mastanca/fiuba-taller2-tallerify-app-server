

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSETEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSETEST_H

#include "gtest/gtest.h"
#include "../src/api/networking/JSONResponse.h"

class JSONResponseTest : public testing::Test {
public:
    JSONResponseTest();
    void TestBody() {}
    void testBodyCreation();
};

TEST_F(JSONResponseTest, testBodyCreation) {
    JSONResponseTest tester;
    tester.testBodyCreation();
}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSETEST_H
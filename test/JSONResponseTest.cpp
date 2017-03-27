

#include "JSONResponseTest.h"

JSONResponseTest::JSONResponseTest() {}

void JSONResponseTest::testBodyCreation() {
    JSONResponse response;
    response["ping"] = "pong";

    ASSERT_EQ(response.getBody(), "{\"ping\":\"pong\"}\n");
}
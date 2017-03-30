

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVERTEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVERTEST_H


#include <gtest/gtest.h>

class ServerTest : public testing::Test {
public:
    ServerTest() {}

    void TestBody() {}

    void controllersRegistrationOnCreation();

};

TEST_F(ServerTest, controllersRegistrarionOnCreation
) {
    ServerTest tester;
    tester.

            controllersRegistrationOnCreation();

}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVERTEST_H

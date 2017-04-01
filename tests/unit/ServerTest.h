

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVERTEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVERTEST_H


#include <gtest/gtest.h>

class ServerTest : public testing::Test {
public:
    ServerTest() {}

    void TestBody() {}

    void testControllersRegistrationOnCreation();

    void testNotFound();

    void testEffectiveHandling();

    void testStop();
};

TEST_F(ServerTest, testControllersRegistrationOnCreation
) {
    ServerTest tester;
    tester.

            testControllersRegistrationOnCreation();

}

TEST_F(ServerTest, testNotFound
) {
    ServerTest tester;
    tester.

            testNotFound();

}

TEST_F(ServerTest, testEffectiveHandling
) {
    ServerTest tester;
    tester.

            testEffectiveHandling();

}

TEST_F(ServerTest, testStop
) {
    ServerTest tester;
    tester.

            testStop();

}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_SERVERTEST_H

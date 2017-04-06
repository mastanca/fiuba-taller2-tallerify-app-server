

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKTEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKTEST_H

#include <gtest/gtest.h>

class TrackTest : public testing::Test {
public:
    TrackTest() {}

    void TestBody() {}

    void testConstruction();
};

TEST_F(TrackTest, testConstruction) {
    TrackTest tester;
    tester.testConstruction();
}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKTEST_H

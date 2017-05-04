

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLERTEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLERTEST_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class TracksControllerTest : public testing::Test {
public:
    TracksControllerTest() {}

    void TestBody() {}

    void testTrackNotFound();

    void testTrackFound();
};

// TEST_F(TracksControllerTest, testTrackNotFound
// ) {
// TracksControllerTest tester;
// tester.
//
// testTrackNotFound();
//
// }
//
// TEST_F(TracksControllerTest, testTrackFound
// ) {
// TracksControllerTest tester;
// tester.
//
// testTrackFound();
//
// }


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLERTEST_H

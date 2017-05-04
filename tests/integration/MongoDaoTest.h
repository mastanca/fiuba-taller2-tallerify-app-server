

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAOTEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAOTEST_H

#include <gtest/gtest.h>

class MongoDaoTest : public testing::Test {
public:
    MongoDaoTest() {}

    void TestBody() {}

    void testGetting();

    void testSaving();
};

 TEST_F(MongoDaoTest, testGetting) {
     MongoDaoTest tester;
     tester.testGetting();
 }

 TEST_F(MongoDaoTest, testSaving) {
     MongoDaoTest tester;
     tester.testSaving();
 }


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAOTEST_H

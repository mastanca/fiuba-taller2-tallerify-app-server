

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_EXAMPLETEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_EXAMPLETEST_H

#include "gtest/gtest.h"

class TestExample : public testing::Test {
public:
    TestExample();
    void TestBody() {}
    void test2plus2();
};

TEST_F(TestExample, test2plus2) {
    TestExample tester;
    tester.test2plus2();
}


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_EXAMPLETEST_H

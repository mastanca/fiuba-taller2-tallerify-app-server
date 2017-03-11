

#include "TestExample.h"

TestExample::TestExample() {}

void TestExample::test2plus2() {
    int four = 2+2;
    ASSERT_EQ(four, 4);
}
#include <gtest/gtest.h>
#include "TestCode.h"

TEST(HelloTest, BasicAssertions) {
    EXPECT_EQ(fourtyTwo(), 42);
}
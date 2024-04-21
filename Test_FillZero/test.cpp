#include "pch.h"
#include "Common.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(Common::fillZero(7, 3), "007");
	EXPECT_EQ(Common::fillZero(9, 4), "0009");
	EXPECT_EQ(Common::fillZero(10, 10), "0000000010");
}
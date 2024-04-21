#include "pch.h"
#include "Common.h"

TEST(TestCaseName, TestName) {

	EXPECT_EQ(4, Common::getMaxLevel(40, 40));
	EXPECT_EQ(1, Common::getMaxLevel(99, 99));
	EXPECT_EQ(3, Common::getMaxLevel(100, 100));
}
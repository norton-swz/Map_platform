#include "pch.h"
#include "Common.h"

TEST(TestCaseName, TestName) {
	QStringList Result = { "E:/Source/cpp/BasicInterface/ThirdParty/mergeAndDownsample/include/framework.h",
									   "E:/Source/cpp/BasicInterface/ThirdParty/mergeAndDownsample/include/mergeAndDownsample.h",
									   "E:/Source/cpp/BasicInterface/ThirdParty/mergeAndDownsample/include/pch.h" };

	EXPECT_EQ(Result[0], Common::getFileListUnderDir("E:\\Source\\cpp\\BasicInterface\\ThirdParty\\mergeAndDownsample\\include")[0]);
	EXPECT_EQ(Result[1], Common::getFileListUnderDir("E:\\Source\\cpp\\BasicInterface\\ThirdParty\\mergeAndDownsample\\include")[1]);
	EXPECT_EQ(Result[2], Common::getFileListUnderDir("E:\\Source\\cpp\\BasicInterface\\ThirdParty\\mergeAndDownsample\\include")[2]);
}
#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <cassert>

extern "C++" __declspec(dllexport) bool mergeAndDownsample2x2Images(const std::string & vImage00, const std::string & vImage01, const std::string & vImage10, const std::string & vImage11, const std::string & vOutputImage);
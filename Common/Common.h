#pragma once

#include "common_global.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <QStringList>
#include <QDir>

class COMMON_EXPORT Common
{
public:
    Common();
    ~Common();
    static QStringList getFileListUnderDir(const QString &vDirPath);
    static std::string fillZero(int vNum, size_t vWidth);
    static int getMaxLevel(int vRows, int vCols);
};

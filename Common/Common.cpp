#include "Common.h"

Common::Common()
{
}

Common::~Common()
{
}

//******************************************************************
//FUNCTION:
std::string Common::fillZero(int vNum, size_t vWidth)
{
    _ASSERTE(vWidth > 0);
    std::ostringstream FormattedNumberStream;
    FormattedNumberStream << std::setw(vWidth) << std::setfill('0') << vNum;
    return FormattedNumberStream.str();
}

//******************************************************************
//FUNCTION:
int Common::getMaxLevel(int vRows, int vCols)
{
    _ASSERTE((vRows > 0) && (vCols > 0));
    int MaxLevel = 1;
    while ((vRows % 2) == 0 && (vCols % 2) == 0)
    {
        MaxLevel++;
        vRows /= 2;
        vCols /= 2;
    }
    return MaxLevel;
}

//******************************************************************
//FUNCTION:
QStringList Common::getFileListUnderDir(const QString &vDirPath)
{
    _ASSERTE(vDirPath != "");
    QStringList FileList;
    QDir Dir(vDirPath);
    QFileInfoList FileInfoList = Dir.entryInfoList(QDir::Files);
    foreach(const QFileInfo & FileInfo, FileInfoList)
    {
        if (FileInfo.isFile())
        {
            FileList.append(FileInfo.absoluteFilePath());
        }
    }
    return FileList;
}
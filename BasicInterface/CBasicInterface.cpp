#include "qmessagebox.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mergeAndDownsample.h"
#include "CBasicInterface.h"

CBasicInterface::CBasicInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CBasicInterfaceClass())
{
    ui->setupUi(this);
    ui->menuFile->addAction("New", this, &CBasicInterface::__onNewActionClick);

    connect(ui->m_ViewPushButton, &QPushButton::clicked, this, &CBasicInterface::__onViewPushButtonClick);
    connect(ui->m_BuildPushButton, &QPushButton::clicked, this, &CBasicInterface::__onBuildPushButtonClick);
}

CBasicInterface::~CBasicInterface()
{
    delete ui;
}

//******************************************************************
//FUNCTION:
void CBasicInterface::__onNewActionClick()
{
    QFileDialog* Dialog = new QFileDialog(this);
    Dialog->setNameFilter("*.txt");
    Dialog->setViewMode(QFileDialog::Detail);
    QString ImageFolderTXT;
    if (Dialog->exec())
        ImageFolderTXT = Dialog->selectedFiles()[0];

    QFile File(ImageFolderTXT);
    if (!File.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream ReadStream(&File);
    QStringList AllLines;
    while (!ReadStream.atEnd())
    {
        AllLines.append(ReadStream.readLine());
    }
    m_Path = AllLines[0];
    m_Rows = AllLines[1].toInt();
    m_Columns = AllLines[2].toInt();
    m_MaxLevel = Common::getMaxLevel(m_Rows, m_Columns);
}

//******************************************************************
//FUNCTION:
void CBasicInterface::__onViewPushButtonClick()
{
    QString Level = ui->lineEdit_2->text();
    Level = "Level_" + Level;
    QString LevelImagePath = m_Path + '\\' + Level;
    QString FirstImagePath = Common::getFileListUnderDir(LevelImagePath)[0];

    QImage Image;
    if (Image.load(FirstImagePath))
    {
        ui->label_3->setPixmap(QPixmap::fromImage(Image));
    }
}

//******************************************************************
//FUNCTION:
void CBasicInterface::__onBuildPushButtonClick()
{
    QString Level = ui->lineEdit->text();
    if (Level.toInt() > m_MaxLevel)
    {
        QMessageBox::warning(nullptr, "warning", "Exceeded maximum build level!", QMessageBox::Ok);
        return;
    }

    // Build multi-level
    for (int i = 2; i <= Level.toInt(); i++)
    {
        int LastLevel = i - 1;
        int NowLevel = LastLevel + 1;
        QString NowBuildLevel = "Level_" + QString::number(NowLevel);
        QString NowBuildLevelImagePath = m_Path + '\\' + NowBuildLevel;
        QString LastLevelImagePath = m_Path + "\\Level_" + QString::number(LastLevel);
        QDir Dir(NowBuildLevelImagePath);
        if (Dir.exists()) // Read the. txt file again every time it is built. If the image set in the file has already been built, skip the level that has already been built
        {
            m_Rows /= 2;
            m_Columns /= 2;
            continue;
        }
        else
        {
            Dir.mkdir(NowBuildLevelImagePath);
        }
        // Obtain the path of all images in the previous level
        QStringList AllImagePath = Common::getFileListUnderDir(LastLevelImagePath);
        for (int i = 0; i < m_Rows; i = i + 2)
        {
            for (int k = 0; k < m_Columns; k = k + 2)
            {
                int Image00 = k + i * m_Columns;
                int Image01 = Image00 + 1;
                int Image10 = Image00 + m_Columns;
                int Image11 = Image10 + 1;
                QString NowRow = QString::number(i / 2 + 1);
                QString NowCol = QString::number(k / 2 + 1);
                // Obtain the image path in the new level after build
                QString AfterBuildImagePath = NowBuildLevelImagePath + '\\' + "Tile_" + QString::fromStdString(Common::fillZero(NowLevel, 3)) + "_" + QString::fromStdString(Common::fillZero(NowRow.toInt(), 3)) + "_" + QString::fromStdString(Common::fillZero(NowCol.toInt(), 3)) + ".png";
                mergeAndDownsample2x2Images(AllImagePath[Image00].toStdString(), AllImagePath[Image01].toStdString(), AllImagePath[Image10].toStdString(), AllImagePath[Image11].toStdString(), AfterBuildImagePath.toStdString());
            }
        }
        // The number of rows and columns in the new level image set needs to be halved
        m_Rows /= 2;
        m_Columns /= 2;
    }
}
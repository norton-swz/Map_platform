#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CBasicInterface.h"
#include "Common.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CBasicInterfaceClass; };
QT_END_NAMESPACE

class  CBasicInterface : public QMainWindow
{
    Q_OBJECT

public:
    CBasicInterface(QWidget *parent = nullptr);
    ~CBasicInterface();

private:
    Ui::CBasicInterfaceClass *ui;
    QString m_Path;
    int m_Rows = 0;
    int m_Columns = 0;
    int m_MaxLevel = 0;

private slots:
    void __onNewActionClick();
    void __onViewPushButtonClick();
    void __onBuildPushButtonClick();
};
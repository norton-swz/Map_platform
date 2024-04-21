#include <QtWidgets/QApplication>
#include "CBasicInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CBasicInterface w;
    w.show();
    return a.exec();
}

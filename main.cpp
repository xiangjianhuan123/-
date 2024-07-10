#include "first.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //用于解决分辨率不同导致的压缩问题
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

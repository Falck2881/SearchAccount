#include "MainWindow.h"
#include <QFile>
#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFile fileStyle(":/Style/EasyCode.qss");
    fileStyle.open(QIODevice::ReadOnly);
    QTextStream stream(&fileStyle);
    app.setStyleSheet(stream.readAll());

    MainWindow winMain;
    winMain.show();
    return app.exec();
}

#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog d;
    MainWindow w(nullptr, &d);
    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include <locale.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Russian");
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1600,800);
    w.show();
    return a.exec();
}

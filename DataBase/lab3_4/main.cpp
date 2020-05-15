#include "mainwindow.h"
#include <locale.h>
#include <QApplication>
#include <QPixmap>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Russian");
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(w.minimumSize());
    w.setWindowTitle("Taxi");
    w.setWindowIcon(QPixmap(":/icons/icon.png"));
    w.show();
    return a.exec();
}

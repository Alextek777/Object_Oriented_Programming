#include "window.h"
#include <QWidget>



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

      window *win = new window();

      win->setWindowTitle("Calculator");

    win->show();





    return a.exec();
}

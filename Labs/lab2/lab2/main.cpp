#include "window.h"
#include <QWidget>
#include <defaultmode.h>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   window *win = new window();

     // DefaultMode *win = new DefaultMode();
    win->show();



    return a.exec();
}

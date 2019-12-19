#include <QApplication>
#include "databasewindow.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    DatabaseWindow win;

    win.show();


   // if(w.isHidden())
     // win.show();

    return a.exec();
}

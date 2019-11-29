#include "window.h"

//#include "my_functions.h"

window::window(QWidget *parent) :  QDialog(parent)
{
    DefaultMode *_defmode1 = new DefaultMode();
    mode1 = _defmode1->final;
    setLayout(mode1);

}

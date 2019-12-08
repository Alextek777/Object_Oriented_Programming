#include "window.h"

//#include "my_functions.h"

window::window(QWidget *parent) :  QMainWindow(parent)
{
    _defmode = new DefaultMode();


    //_defmode->show();

    mode1 = new QHBoxLayout(this);


    mode1->addWidget(_defmode);
    //setLayout(mode1);
    setCentralWidget(_defmode);

    connect(_defmode->ult,SIGNAL(clicked()),this,SLOT(ultimate_mode_clicked()));
}



void window::ultimate_mode_clicked()
{
    _ultmode = new UltimateMode(_defmode);
    mode1->addWidget(_ultmode);
    this->resize(600,574);


//    mode2->addLayout(mode1);
//    setLayout(mode2);

//    this->resize(400, 574);
}

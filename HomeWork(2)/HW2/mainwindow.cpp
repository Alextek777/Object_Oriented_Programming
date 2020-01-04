#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->resize(400,600);

    menu = new QMenu("&File");

    QAction *open_action = new QAction("Open XML file");
    open_action->setText("Open");
    open_action->setShortcut(QKeySequence("CTRL+O"));
    open_action->setToolTip("open Document");
    open_action->setStatusTip("Open and parse XML documents1");
    open_action->setWhatsThis("Open and parse XML documents2");
    open_action->setIcon(QPixmap("C:/Users/alext/Desktop/University/Semester 3/OOP/HW/HomeWork(2)/img/open.png"));
    menu->addAction(open_action);
    connect(open_action,SIGNAL(triggered()),SLOT(open_slot));

//    QAction *close_action = new QAction("close XML file");
//    close_action->setText("close");
//    close_action->setShortcut(QKeySequence("CTRL+X"));
//    close_action->setToolTip("close Documents");
//    close_action->setStatusTip("close documents1");
//    close_action->setWhatsThis("close documents2");
//    close_action->setIcon(QPixmap("C:/Users/alext/Desktop/University/Semester 3/OOP/HW/HomeWork(2)/img/close.png"));
//    connect(close_action,SIGNAL(triggered()),SLOT(close_slot));
//    menu->addAction(close_action);






}

MainWindow::~MainWindow()
{

}

void MainWindow::open_slot()
{

}


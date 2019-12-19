#include "databasewindow.h"
#include "ui_databasewindow.h"



DatabaseWindow::DatabaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseWindow)
{
    ui->setupUi(this);
    w.show();
}

DatabaseWindow::~DatabaseWindow()
{
    delete ui;
}

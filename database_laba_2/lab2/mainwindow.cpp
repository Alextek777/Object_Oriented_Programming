#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

//QString db_ip;
//QString db_port;
//QString db_name;
//QString db_login;
//QString db_pass;

//QSqlDatabase myDb = QSqlDatabase::addDatabase("QPSQL");
//QSqlQuery myQuerry(myDb);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->OK_button,SIGNAL(clicked()),this,SLOT(connect_db()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connect_db()
{

    db_ip = ui->line_IP->text();
    db_port = ui->line_port->text();
    db_name = ui->line_db_name->text();
    db_login = ui->line_login->text();
    db_pass = ui->line_pass->text();


    myDb.setDatabaseName(db_name);
    myDb.setHostName(db_ip);
        myDb.setPort(db_port.toInt());
        myDb.setUserName(db_login);
        myDb.setPassword(db_pass);

        if(!myDb.open())
            std::cout << "couldn`t open database!!!" << std::endl;
                                else
                                {
//                                    std::cout << "database opened successfully" << std::endl;
//                                    if(!myQuerry.exec("CREATE TABLE fn11tek(id INT NOT NULL,name VARCHAR(30),age INT)"))
//                                        qDebug() << myQuerry.lastError().text();
//                                    if(!myQuerry.exec("INSERT INTO fn11tek(id,name,age) VALUES (1,'alex',18),(2,'tektumanidze',19)"))
//                                        qDebug() << myQuerry.lastError().text();
                                    if(!myQuerry.exec("SELECT * FROM oskars_"))
                                        qDebug() << myQuerry.lastError().text();
                                    if(myQuerry.isSelect())
                                    {
                                    while(myQuerry.next())
                                        {
                                            qDebug() << myQuerry.record();
                                        }
                                    }
                                    else
                                      qDebug() << myQuerry.lastError().text();

                                    if(!myQuerry.exec("DROP TABLE fn11tek"))
                                        qDebug() << myQuerry.lastError();
                                }
//            else
//                std::cout << "Database successfully connected!!!" << std::endl;

        this->close();



        //close();
}



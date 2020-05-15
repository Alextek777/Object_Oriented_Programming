#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_humidity->setReadOnly(true);
    ui->lineEdit_temperature->setReadOnly(true);
    ui->radioButton_celsius->setChecked(true);


    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress::LocalHost,1234,QIODevice::ReadOnly);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(ui->radioButton_kelvin,SIGNAL(clicked()),this,SLOT(radiobuttonChanged()));
    connect(ui->radioButton_celsius,SIGNAL(clicked()),this,SLOT(radiobuttonChanged()));
    connect(ui->radioButton_fahrenheit,SIGNAL(clicked()),this,SLOT(radiobuttonChanged()));
    connect(ui->pushbutton_buildGraph,SIGNAL(clicked()),this,SLOT(createPlot()));
    if(!socket->isOpen())
    {
        qDebug() << "couldn`t connect to server!";
        return;
    }
    else
        qDebug() << "cunnected to server!";


}



void MainWindow::readyRead()
{
    QString data = socket->readAll();
    qDebug() << "data: " << data;
    if(data == "nan$nan")
    {
        qDebug() << "junk data";
        return;
    }
    humidity = data.mid(6,10);
    Temperature = data.mid(0,4);

    temp.push_back(Temperature.toDouble());

    ui->lineEdit_humidity->setText(humidity);

    if(ui->radioButton_celsius->isChecked())
        ui->lineEdit_temperature->setText(Temperature);

        else if(ui->radioButton_kelvin->isChecked())
        {
            float kelvin_float = Temperature.toFloat() + 273.15;
            ui->lineEdit_temperature->setText(QString::number(kelvin_float));
        }
            else if(ui->radioButton_fahrenheit->isChecked())
            {
                float fahrenheit_float = (Temperature.toFloat()*9/5)+32;
                ui->lineEdit_temperature->setText(QString::number(fahrenheit_float));
            }
}


void MainWindow::radiobuttonChanged()
{
    if(ui->radioButton_celsius->isChecked())
        ui->lineEdit_temperature->setText(Temperature);

        else if(ui->radioButton_kelvin->isChecked())
        {
            float kelvin_float = Temperature.toFloat() + 273.15;
            ui->lineEdit_temperature->setText(QString::number(kelvin_float));
        }
            else if(ui->radioButton_fahrenheit->isChecked())
            {
                float fahrenheit_float = (Temperature.toFloat()*9/5)+32;
                ui->lineEdit_temperature->setText(QString::number(fahrenheit_float));
            }
}

void MainWindow::createPlot()
{
    customPlot = new QCustomPlot;
    customPlot->resize(600,400);

    customPlot->addGraph();

    time.resize(temp.size());
    value.resize(temp.size());

    for(int i=0;i<temp.size();i++)
    {
        time[i] = i/10;
        value[i] = temp[i];
    }
    customPlot->graph(0)->setData(time,value);

    customPlot->xAxis->setLabel("Time");
    customPlot->yAxis->setLabel("Temperature (Celsius)");
    customPlot->xAxis->setRange(0,temp.size()/5);
    customPlot->yAxis->setRange(0,40);
    customPlot->replot();
    customPlot->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


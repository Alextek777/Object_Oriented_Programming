#include "mysocket.h"

QByteArray MySocket::incomingData = "hello";

MySocket::MySocket(int socketDescriptor,QObject *parent):QTcpSocket(parent)
{
    this->setSocketDescriptor(socketDescriptor);
    this->descriptor = socketDescriptor;

    connect(this,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sendDataToClients()),Qt::DirectConnection);
    timer->start(3000); //time specified in ms

}




void MySocket::readyRead()
{
    incomingData = readAll();
    qDebug() << socketDescriptor() << " Data in: " << incomingData;
}

void MySocket::sendDataToClients()
{
    if(this->isOpen() && !incomingData.isEmpty())
    {
        write(incomingData);
        waitForBytesWritten(100);
        qDebug() << "sending data:      " << incomingData << "      to client: " << socketDescriptor();
    }
    else
        qDebug() << "couldn`t send data to client   State: " << this->state();
}





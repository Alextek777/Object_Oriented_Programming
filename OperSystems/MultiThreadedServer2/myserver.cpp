#include "myserver.h"

MyServer::MyServer(QObject *parent):QTcpServer(parent)
{

}


void MyServer::startServer()
{
    if(!listen(QHostAddress::Any,1234))
        qDebug() << "Couldn`t start client server!";
    else
        qDebug() << "Client server listening...";
}


void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " connectiong...";
    QThread *thread = new QThread(this);
    MySocket *my_socket = new MySocket(socketDescriptor);

    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(my_socket,SIGNAL(disconnected()),this,SLOT(disconnected()));

    my_socket->moveToThread(thread);
    thread->start();

    threads.push_back(thread);
    sockets.push_back(my_socket);

    if(my_socket->isOpen())
        qDebug() << my_socket->descriptor << " connected!";
    else
        qDebug() << my_socket->descriptor << " couldn`t connect socket!";
}



void MyServer::disconnected()
{
    MySocket *my_socket =dynamic_cast<MySocket*>(sender());
    qDebug() << my_socket->descriptor << " disconnected!";
    my_socket->thread()->quit();

    threads.erase(std::find(threads.begin(),threads.end(),my_socket->thread()));
    sockets.erase(std::find(sockets.begin(),sockets.end(),my_socket));
}



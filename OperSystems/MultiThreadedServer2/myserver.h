#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include <QVector>
#include <QThread>

#include "mysocket.h"


class MyServer : public QTcpServer
{
Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);

    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;


private:
    QVector<QThread*> threads;
    QVector<MySocket*> sockets;

public slots:
    void disconnected();
};

#endif // MYSERVER_H

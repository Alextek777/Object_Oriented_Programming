#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QAbstractSocket>
#include <QThread>

class MyServer;
class MySocket : public QTcpSocket
{
Q_OBJECT
public:
    MySocket(int socketDescriptor,QObject *parent = nullptr);
    friend MyServer;

public slots:
    void readyRead();
    void sendDataToClients();


private:
    int descriptor;
    static QByteArray incomingData;

    //QTimer *timer;
};

#endif // MYSOCKET_H

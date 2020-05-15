#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include <QWidget>

#include "qcustomplot.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;

    QString Temperature;
    QString humidity;

    QCustomPlot *customPlot;

    QVector<double> temp;

    QVector<double> time;
    QVector<double> value;
private slots:
    void readyRead();
    void radiobuttonChanged();
    void createPlot();
};
#endif // MAINWINDOW_H

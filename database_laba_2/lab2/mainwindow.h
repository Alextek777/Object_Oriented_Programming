#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QVariant>





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

    QString db_ip;
    QString db_port;
    QString db_name;
    QString db_login;
    QString db_pass;

    QSqlDatabase myDb = QSqlDatabase::addDatabase("QPSQL");
    QSqlQuery myQuerry;



private slots:
    void connect_db();

};
#endif // MAINWINDOW_H

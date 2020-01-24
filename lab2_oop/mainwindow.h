#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QStringListModel>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QTextBrowser>

#include <customhighlighter.h>


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
    void load_dataDase_stringModel();


private slots:
    void connect_database();
    void load_table();
    void run_button_clicked();


private:
    Ui::MainWindow *ui;
    QSqlDatabase data_base = QSqlDatabase::addDatabase("QPSQL");
    QSqlQuery *query;
    QSqlRecord record;
    QStringListModel list_model;
    QSqlQueryModel table_model;
    QStringList list_table_names;
    CustomHighlighter *highlighter;
    int history_index = 1;
    QStringList command_history;
    int current_command = 0;


protected:
    bool eventFilter(QObject *obj,QEvent *event)override;
};





#endif // MAINWINDOW_H



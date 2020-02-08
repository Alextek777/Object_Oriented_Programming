#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlRecord>
#include <QMessageBox>
#include <QAction>
#include <QtSql/QSqlQueryModel>
#include <QDate>

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

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    QSqlQuery *query;
    QSqlQueryModel model_outlays,model_rent,model_tab2,model_tech;
    QString first_date,second_date;


private:
    void connect_database();
    void create_bars();
    void create_calendars();
private slots:
    void next_day_slot();
    void set_today_outlays();
    void get_first_date();
    void get_second_date();
    void rent_car();
    void add_car();
    void change_parameters();
    void calendar_add_rentaable_cars();
};
#endif // MAINWINDOW_H

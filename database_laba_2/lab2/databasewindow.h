#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class DatabaseWindow;
}

class DatabaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseWindow(QWidget *parent = nullptr);
    ~DatabaseWindow();

private:
    Ui::DatabaseWindow *ui;
    MainWindow w;

    friend MainWindow;
};

#endif // DATABASEWINDOW_H

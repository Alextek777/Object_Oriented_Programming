#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QRadioButton>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>

#include "defaultmode.h"

#include <QTextEdit>


class window : public QMainWindow
{
    Q_OBJECT

    friend class DefaultMode;
public:
    window(QWidget *parent= nullptr);




private:
     DefaultMode *_defmode;
     UltimateMode *_ultmode;
     QHBoxLayout *mode1;
     //QHBoxLayout *mode2;
   // QString memory_string;
   // QWidget *mode1;

private slots:
     void ultimate_mode_clicked();



};

#endif // WINDOW_H

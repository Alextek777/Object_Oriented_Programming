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

#include "defaultmode.h"

#include <QTextEdit>


class window : public QDialog
{
    Q_OBJECT

    friend class DefaultMode;
public:
    window(QWidget *parent= nullptr);




private:
    QVBoxLayout *mode1;
   // QString memory_string;
   // QWidget *mode1;



};

#endif // WINDOW_H

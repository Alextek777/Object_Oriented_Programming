#ifndef DEFAULTMODE_H
#define DEFAULTMODE_H

#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

#include "ultimatemode.h"
#include <QTextEdit>

class DefaultMode : public  QDialog
{
    Q_OBJECT

    //friend class window;
public:
    explicit DefaultMode(QDialog *parent = nullptr);
    friend class window;
private:
    QLabel *LCDNUM;

    //QTextEdit *mytext;
    QString current_text;
    QString saved_text;

    QPushButton *zero,*one,*two,*three,*four,*five,*six,
    *seven,*eight,*nine,*plus,*minus,*dot,*mult,*devide,
    *sqrt_but,*rev,*equals,*clean;

    QRadioButton *def,*ult;

     //final layout
     QVBoxLayout *final;

     UltimateMode *ultimate_mode_widget;

private slots:

//    void deffault_mode_radiobutton();
//    void ultimate_mode_radiobutton();


    void num_clicked();
    void operation_clicked();
    void equals_clicked();
    void clean_label();

};

#endif // DEFAULTMODE_H

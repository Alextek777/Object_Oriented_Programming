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


#include <QTextEdit>

class DefaultMode : public  QDialog
{
    Q_OBJECT

    //friend class window;
public:
    DefaultMode(QWidget *parent = nullptr);
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

    QVBoxLayout *final;     //final layout

private slots:

    void deffault_mode();
    void ultimate_mode();


    void num_clicked();
    void operation_clicked();
    void equals_clicked();
    void clean_label();

};

#endif // DEFAULTMODE_H

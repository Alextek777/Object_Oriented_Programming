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
#include <QtMath>

#include <QTextEdit>


class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QMainWindow *parent= nullptr);




private:
    QWidget *cent_wgt;
    QWidget *default_calculator;
    QWidget *engineer_calculator;

     QGridLayout *grid_default;
     QGridLayout *grid_engineer;

    //---------------------------------default-------------------------
private:
     QLabel *LCDNUM;

     QString current_text;
     QString saved_text;

     QPushButton *zero,*one,*two,*three,*four,*five,*six,
     *seven,*eight,*nine,*plus,*minus,*dot,*mult,*devide,
     *sqrt_but,*rev,*equals,*clean;

     QRadioButton *def,*ult;

      //final layout
      QHBoxLayout *final;
      //------------------------ult---------------------------------------------
private:
      QPushButton *sinh,*cosh,*tanh,*n_fact,*sin,*cos,*tan,*contant_pi,*exp,*ln,*log,*root_3x,*power_2,*power_3,*power_y,*root_yx;
      QGridLayout *grid_layout;
      void connect_slots();

      void setting_layouts();

private slots:
     void ultimate_mode_clicked();
     void default_mode_clicked();

private slots:  //defmode

    void engineer_operation_clicked();
    void num_clicked();
    void operation_clicked();
    void equals_clicked();
    void clean_label();



};

#endif // WINDOW_H

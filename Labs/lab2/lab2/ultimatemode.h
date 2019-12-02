#ifndef ULTIMATEMODE_H
#define ULTIMATEMODE_H

#include <QObject>
#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>



#include <QTextEdit>

class UltimateMode : public QDialog
{
    Q_OBJECT
public:
    explicit UltimateMode(QDialog *parent = nullptr);
    friend class DefaultMode;
private:
    QPushButton *sinh,*cosh,*tanh,*n_fact,*sin,*cos,*tan,*contant_pi,*exp,*ln,*log,*root_3x,*power_2,*power_3,*power_y,*root_yx;
    QGridLayout *grid_layout;


signals:

public slots:
};

#endif // ULTIMATEMODE_H

#include "ultimatemode.h"

UltimateMode::UltimateMode(QDialog *parent) : QDialog(parent)
{

    sinh = new QPushButton("sinh");
    cosh = new QPushButton("cosh");
    tanh = new QPushButton("tanh");
    n_fact = new QPushButton("n!");
    sin = new QPushButton("sin");
    cos = new QPushButton("cos");
    tan = new QPushButton("tan");
    contant_pi = new QPushButton("Pi");
    exp = new QPushButton("exp");
    ln = new QPushButton("ln");
    log = new QPushButton("log");
    root_3x = new QPushButton("√");
    power_2 = new QPushButton("x^2");
    power_3 = new QPushButton("x^3");
    power_y = new QPushButton("x^y");
    root_yx = new QPushButton("root_yx");






    sinh->setFixedSize(60,60);
    cosh->setFixedSize(60,60);
    tanh->setFixedSize(60,60);
    n_fact->setFixedSize(60,60);
    sin ->setFixedSize(60,60);
    cos ->setFixedSize(60,60);
    tan ->setFixedSize(60,60);
    contant_pi ->setFixedSize(60,60);
    exp ->setFixedSize(60,60);
    ln ->setFixedSize(60,60);
    log->setFixedSize(60,60);
    root_3x ->setFixedSize(60,60);
    power_2 ->setFixedSize(60,60);
    power_3->setFixedSize(60,60);
    power_y ->setFixedSize(60,60);
    root_yx ->setFixedSize(60,60);





    grid_layout = new QGridLayout();
    grid_layout->addWidget(sinh,0,0);
    grid_layout->addWidget(cosh,0,1);
    grid_layout->addWidget(tanh,0,2);
    grid_layout->addWidget(n_fact,0,3);
    grid_layout->addWidget(sin,1,0);
    grid_layout->addWidget(cos,1,1);
    grid_layout->addWidget(tan,1,2);
    grid_layout->addWidget(contant_pi,1,3);
    grid_layout->addWidget(exp,2,0);
    grid_layout->addWidget(ln,2,1);
    grid_layout->addWidget(log,2,2);
    grid_layout->addWidget(root_3x,2,3);
    grid_layout->addWidget(power_2,3,0);
    grid_layout->addWidget(power_3,3,1);
    grid_layout->addWidget(power_y,3,2);
    grid_layout->addWidget(root_yx,3,3);

    setLayout(grid_layout);


}

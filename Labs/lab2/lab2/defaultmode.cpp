#include "defaultmode.h"
#include <QtMath>

DefaultMode::DefaultMode(QWidget *parent) : QDialog(parent)
{

    //-------------------------------------------LABEL_SETTINGS--------------------------------------------------------------------------------------


    LCDNUM = new QLabel();
    LCDNUM->setStyleSheet("QLabel {qproperty-alignment: 'AlignVCenter | AlignRight';border: 1px solid gray;}background-color : white;");
   // LCDNUM->setNum(0);
    QFont font = LCDNUM->font();
    font.setPointSize(30);
    font.setBold(true);
    LCDNUM->setFont(font);

    //-------------------------------------------BUTTON_SETTINGS-------------------------------------------------------------------------------------

    zero = new QPushButton("0");
    one = new QPushButton("1");
    two = new QPushButton("2");
    three = new QPushButton("3");
    four = new QPushButton("4");
    five = new QPushButton("5");
    six = new QPushButton("6");
    seven = new QPushButton("7");
    eight = new QPushButton("8");
    nine = new QPushButton("9");
    plus = new QPushButton("+");
    minus = new QPushButton("-");
    dot = new QPushButton(".");
    mult = new QPushButton("*");
    devide = new QPushButton("/");
    sqrt_but = new QPushButton("K");
    rev = new QPushButton("R");
    equals = new QPushButton("=");
    clean = new QPushButton("C");
    def = new QRadioButton("Default");
    ult = new QRadioButton("Ultra Mode");


    LCDNUM->setFixedSize(380,140);
    zero->setMinimumWidth(148);
    zero->setMinimumHeight(70);
    //zero->setFixedSize(148,70);
    one->setFixedSize(70,70);
    two->setFixedSize(70,70);
    three->setFixedSize(70,70);
    four->setFixedSize(70,70);
    five->setFixedSize(70,70);
    six->setFixedSize(70,70);
    seven->setFixedSize(70,70);
    eight->setFixedSize(70,70);
    nine->setFixedSize(70,70);
    plus->setFixedSize(70,70);
    minus->setFixedSize(70,70);
    dot->setFixedSize(70,70);
    mult->setFixedSize(70,70);
    devide->setFixedSize(70,70);
    sqrt_but->setFixedSize(70,70);
    rev->setFixedSize(70,70);
    equals->setFixedSize(70,150);
    clean->setFixedSize(70,70);

    def = new QRadioButton("Default");
    equals->setDefault(true);
    def->setChecked(true);

    one->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    two->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    three->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    four->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    five->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    six->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    seven->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    eight->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    nine->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
    zero->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");

    plus->setStyleSheet("QPushButton {background-color: rgb(255, 151, 57);color: white; border: 1px solid gray;}            QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FF7832, stop: 1 #FF9739);}");
    minus->setStyleSheet("QPushButton {background-color: rgb(255, 151, 57);color: white; border: 1px solid gray;}            QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FF7832, stop: 1 #FF9739);}");
    mult->setStyleSheet("QPushButton {background-color: rgb(255, 151, 57);color: white; border: 1px solid gray;}            QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FF7832, stop: 1 #FF9739);}");
    devide->setStyleSheet("QPushButton {background-color: rgb(255, 151, 57);color: white; border: 1px solid gray;}            QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FF7832, stop: 1 #FF9739);}");
    dot->setStyleSheet("QPushButton {background-color: rgb(255, 151, 57);color: white; border: 1px solid gray;}            QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FF7832, stop: 1 #FF9739);}");


    equals->setStyleSheet("QPushButton {background-color: rgb(215, 215, 215);border: 1px solid gray;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BEBEBE, stop: 1 #D7D7D7);}");
    rev->setStyleSheet("QPushButton {background-color: rgb(215, 215, 215);border: 1px solid gray;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BEBEBE, stop: 1 #D7D7D7);}");
    sqrt_but->setStyleSheet("QPushButton {background-color: rgb(215, 215, 215);border: 1px solid gray;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BEBEBE, stop: 1 #D7D7D7);}");
    equals->setStyleSheet("QPushButton {background-color: rgb(215, 215, 215);border: 1px solid gray;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BEBEBE, stop: 1 #D7D7D7);}");
    clean->setStyleSheet("QPushButton {background-color: rgb(215, 215, 215);border: 1px solid gray;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BEBEBE, stop: 1 #D7D7D7);}");


   // const QSize BUTTON_SIZE = QSize(50, 50);
   // one->resize(BUTTON_SIZE);

    //------------------------------------------LAYOUT SETTINGS--------------------------------------------------------------------------------------
    QVBoxLayout *l1 = new QVBoxLayout;
    l1->addWidget(def);
    l1->addWidget(ult);

    QHBoxLayout *l2 = new QHBoxLayout;
    l2->addLayout(l1);
    l2->addWidget(clean);

    QVBoxLayout *l3 = new QVBoxLayout;
    l3->addWidget(LCDNUM);
    l3->addLayout(l2);

    QHBoxLayout *l4 = new QHBoxLayout;
    l4->addWidget(seven);
    l4->addWidget(eight);
    l4->addWidget(nine);
    l4->addWidget(devide);
    l4->addWidget(sqrt_but);

    QHBoxLayout *l5 = new QHBoxLayout;
    l5->addWidget(four);
    l5->addWidget(five);
    l5->addWidget(six);
    l5->addWidget(mult);
    l5->addWidget(rev);

    QHBoxLayout *l6 = new QHBoxLayout;
    l6->addWidget(one);
    l6->addWidget(two);
    l6->addWidget(three);
    l6->addWidget(minus);

    QHBoxLayout *l7 = new QHBoxLayout;
    l7->addWidget(dot);
    l7->addWidget(plus);

    QHBoxLayout *l8 = new QHBoxLayout;
    l8->addWidget(zero);
    l8->addLayout(l7);

    QVBoxLayout *l9 = new QVBoxLayout;
    l9->addLayout(l6);
    l9->addLayout(l8);

    QHBoxLayout *l10 = new QHBoxLayout;
    l10->addLayout(l9);
    l10->addWidget(equals);

    final = new QVBoxLayout;
    final->addLayout(l3);
    final->addLayout(l4);
    final->addLayout(l5);
    final->addLayout(l10);

    //setLayout(final);

    //-----------------------------------------------------------------------------------------------------------------------------------------------


    //-------------------------------------------CONNECT_SLOTS---------------------------------------------------------------------------------------



    connect(this->def,SIGNAL(clicked()),this,SLOT(deffault_mode()));
    connect(this->ult,SIGNAL(clicked()),this,SLOT(ultimate_mode()));


    connect(one,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(two,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(three,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(four,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(five,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(six,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(seven,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(eight,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(nine,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(zero,SIGNAL(clicked()),this,SLOT(num_clicked()));
    connect(dot,SIGNAL(clicked()),this,SLOT(num_clicked()));

    connect(clean,SIGNAL(clicked()),this,SLOT(clean_label()));
    connect(equals,SIGNAL(clicked()),this,SLOT(equals_clicked()));

    connect(plus,SIGNAL(clicked()),this,SLOT(operation_clicked()));
    connect(minus,SIGNAL(clicked()),this,SLOT(operation_clicked()));
    connect(mult,SIGNAL(clicked()),this,SLOT(operation_clicked()));
    connect(devide,SIGNAL(clicked()),this,SLOT(operation_clicked()));
    connect(sqrt_but,SIGNAL(clicked()),this,SLOT(operation_clicked()));
    connect(rev,SIGNAL(clicked()),this,SLOT(operation_clicked()));





}

//----------------------------------SLOTS----------------------------------------------------------------------------------------------

void DefaultMode::deffault_mode()
{

}

void DefaultMode::ultimate_mode()
{

}

void DefaultMode::num_clicked()
{
    QString new_str_text;
    QPushButton *button_clicked = (QPushButton*)sender();
    double new_double_text = (LCDNUM->text() + button_clicked->text()).toDouble();
    current_text += button_clicked->text();
    if(new_double_text > 99999999)
         new_str_text = "MAX SIZE!";
    else
         new_str_text = QString::number(new_double_text,'g',6);
    LCDNUM->setText(new_str_text);
}

    void DefaultMode::clean_label()
    {
      LCDNUM->setText("");
      current_text="";
      saved_text="";
    }

    void DefaultMode::operation_clicked()
    {
               LCDNUM->setText("");
               QPushButton *button_clicked = (QPushButton*)sender();
        if(current_text == "")saved_text+=button_clicked->text();
        else if(current_text.size() > 0 && current_text[current_text.size()-1] != "*" && current_text[current_text.size()-1] != "+" && current_text[current_text.size()-1] != "-" && current_text[current_text.size()-1] != "/")
        {
            current_text += button_clicked->text();
            saved_text = current_text;
            current_text = "";
        }
        //QString butname = button_clicked->text();
        if(button_clicked->text() == 'K' || button_clicked->text() == 'R')
            emit(equals_clicked());
    }

    void DefaultMode::equals_clicked()
    {
        if(saved_text == "")LCDNUM->setNum(current_text.toDouble());
        else
        {
           QChar oper = saved_text[saved_text.size()-1];
           saved_text.resize(saved_text.size()-1);
           double first_number = saved_text.toDouble();

           double second_number = current_text.toDouble();

           double result;

            if(oper == '+')result=first_number+second_number;
            if(oper == '-')result=first_number-second_number;
            if(oper == '*')result=first_number*second_number;
            if(oper == '/')result=first_number/second_number;

            if(oper == "K")result=qSqrt(first_number);
            if(oper == "R")result=1/first_number;


            LCDNUM->setNum(result);
            saved_text = QString::number(result);
            current_text = "";
        }
    }





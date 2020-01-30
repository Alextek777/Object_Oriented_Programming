#include "window.h"

//#include "my_functions.h"

window::window(QMainWindow *parent) :  QMainWindow(parent)
{

    cent_wgt = new QWidget(this);
    default_calculator = new QWidget(this);
    engineer_calculator = new QWidget(this);


    setting_layouts();
    connect_slots();

}



void window::ultimate_mode_clicked()
{
    engineer_calculator->setVisible(true);
    this->setMaximumWidth(800);
    this->setMinimumWidth(800);

}

void window::default_mode_clicked()
{
    engineer_calculator->setVisible(false);
    this->setMinimumSize(400,500);
    this->setMaximumSize(400,500);



}



void window::num_clicked()
{
    QString new_str_text;
    double new_double_text;
    QPushButton *button_clicked = (QPushButton*)sender();

            new_double_text = (LCDNUM->text() + button_clicked->text()).toDouble();
            current_text += button_clicked->text();
            if(new_double_text > 99999999)
                 new_str_text = "MAX \n SIZE!";
            else
                 new_str_text = QString::number(new_double_text,'g',5);

    LCDNUM->setText(new_str_text);
}

    void window::clean_label()
    {
      LCDNUM->setText("");
      current_text="";
      saved_text="";
    }

    void window::operation_clicked()
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



    void window::equals_clicked()
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
            if(oper == "X")result=qPow(first_number,second_number);
            if(oper == "x")result=qPow(first_number,1/second_number);


            if(oper == "K")result=qSqrt(first_number);
            if(oper == "R")result=1/first_number;
            if(oper == "S")result=(qExp(first_number) - qExp(-1*first_number))/2;
            if(oper == "C")result=(qExp(first_number) + qExp(-1*first_number))/2;
            if(oper == "T")result=(qExp(first_number) - qExp(-1*first_number))/(qExp(first_number) + qExp(-1*first_number));
            if(oper == "s")result=qSin(first_number);
            if(oper == "c")result=qCos(first_number);
            if(oper == "t")result=qTan(first_number);
            if(oper == "P")result=3.141592;
            if(oper == "e")result=2.718281;
            if(oper == "L")result=qLn(first_number);
            if(oper == "q")result=first_number*first_number;
            if(oper == "Q")result=first_number*first_number*first_number;
            if(oper == 'l')result=log10(first_number);




            LCDNUM->setNum(result);
            saved_text = QString::number(result);
            current_text = "";
        }
    }


    void window::engineer_operation_clicked()
    {

        LCDNUM->setText("");
                QPushButton *buf = (QPushButton*)sender();
        saved_text=current_text;
        current_text="";

        if(buf->text() == "sinh") {saved_text += "S"; emit equals_clicked();}
        if(buf->text() == "cosh") {saved_text += "C"; emit equals_clicked();}
        if(buf->text() == "tanh") {saved_text += "T"; emit equals_clicked();}
        if(buf->text() == "n!") {saved_text += "N"; emit equals_clicked();}
        if(buf->text() == "sin") {saved_text += "s"; emit equals_clicked();}
        if(buf->text() == "cos") {saved_text += "c"; emit equals_clicked();}
        if(buf->text() == "tan") {saved_text += "t"; emit equals_clicked();}
        if(buf->text() == "Pi") {saved_text += "P"; emit equals_clicked();}
        if(buf->text() == "exp") {saved_text += "e"; emit equals_clicked();}
        if(buf->text() == "ln") {saved_text += "L"; emit equals_clicked();}
        if(buf->text() == "log") {saved_text += "l"; emit equals_clicked();}
        if(buf->text() == "sqrt") {saved_text += "R"; emit equals_clicked();}
        if(buf->text() == "x^2") {saved_text += "q"; emit equals_clicked();}
        if(buf->text() == "x^3") {saved_text += "Q"; emit equals_clicked();}
        if(buf->text() == "x^y") saved_text += "X";
        if(buf->text() == "root_yx") saved_text += "x";

    }

    void window::connect_slots()
    {
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
        connect(ult,SIGNAL(clicked()),this,SLOT(ultimate_mode_clicked()));
        connect(def,SIGNAL(clicked()),this,SLOT(default_mode_clicked()));



        connect(sinh,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(cosh,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(tanh,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(n_fact,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(sin ,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(cos ,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(tan ,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(contant_pi ,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(exp ,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(ln ,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(log,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(root_3x ,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(power_2,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(power_3,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(power_y,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
        connect(root_yx,SIGNAL(clicked()),this,SLOT(engineer_operation_clicked()));
    }



    void window::setting_layouts()
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

        zero = new QPushButton("0",this);
        one = new QPushButton("1",this);
        two = new QPushButton("2",this);
        three = new QPushButton("3",this);
        four = new QPushButton("4",this);
        five = new QPushButton("5",this);
        six = new QPushButton("6",this);
        seven = new QPushButton("7",this);
        eight = new QPushButton("8",this);
        nine = new QPushButton("9",this);
        plus = new QPushButton("+",this);
        minus = new QPushButton("-",this);
        dot = new QPushButton(".",this);
        mult = new QPushButton("*",this);
        devide = new QPushButton("/",this);
        sqrt_but = new QPushButton("K",this);
        rev = new QPushButton("R",this);
        equals = new QPushButton("=",this);
        clean = new QPushButton("C",this);
        def = new QRadioButton("Default",this);
        ult = new QRadioButton("Ultra Mode",this);



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



        QVBoxLayout *l1 = new QVBoxLayout(this);
        l1->addWidget(def);
        l1->addWidget(ult);

        QHBoxLayout *l2 = new QHBoxLayout(this);
        l2->addLayout(l1);
        l2->addWidget(clean);

        QVBoxLayout *vertical_layout = new QVBoxLayout(this);
        vertical_layout->addWidget(LCDNUM);
        vertical_layout->addLayout(l2);


        grid_default = new QGridLayout(this);
        grid_default->addWidget(seven,0,0,1,1);
        grid_default->addWidget(eight,0,1,1,1);
        grid_default->addWidget(nine,0,2,1,1);
        grid_default->addWidget(mult,0,3,1,1);
        grid_default->addWidget(sqrt_but,0,4,1,1);
        grid_default->addWidget(four,1,0,1,1);
        grid_default->addWidget(five,1,1,1,1);
        grid_default->addWidget(six,1,2,1,1);
        grid_default->addWidget(devide,1,3,1,1);
        grid_default->addWidget(rev,1,4,1,1);
        grid_default->addWidget(one,2,0,1,1);
        grid_default->addWidget(two,2,1,1,1);
        grid_default->addWidget(three,2,2,1,1);
        grid_default->addWidget(plus,2,3,1,1);
        grid_default->addWidget(equals,2,4,2,1);
        grid_default->addWidget(zero,3,0,1,2);
        grid_default->addWidget(dot,3,2,1,1);
        grid_default->addWidget(minus,3,3,1,1);

       default_calculator->setLayout(grid_default);

       sinh = new QPushButton("sinh", this);
       cosh = new QPushButton("cosh", this);
       tanh = new QPushButton("tanh", this);
       n_fact = new QPushButton("n!", this);
       sin = new QPushButton("sin", this);
       cos = new QPushButton("cos", this);
       tan = new QPushButton("tan", this);
       contant_pi = new QPushButton("Pi", this);
       exp = new QPushButton("exp", this);
       ln = new QPushButton("ln", this);
       log = new QPushButton("log", this);
       root_3x = new QPushButton("sqrt", this);
       power_2 = new QPushButton("x^2", this);
       power_3 = new QPushButton("x^3", this);
       power_y = new QPushButton("x^y", this);
       root_yx = new QPushButton("root_yx", this);






       sinh->setFixedSize(70,70);
       cosh->setFixedSize(70,70);
       tanh->setFixedSize(70,70);
       n_fact->setFixedSize(70,70);
       sin ->setFixedSize(70,70);
       cos ->setFixedSize(70,70);
       tan ->setFixedSize(70,70);
       contant_pi ->setFixedSize(70,70);
       exp ->setFixedSize(70,70);
       ln ->setFixedSize(70,70);
       log->setFixedSize(70,70);
       root_3x ->setFixedSize(70,70);
       power_2 ->setFixedSize(70,70);
       power_3->setFixedSize(70,70);
       power_y ->setFixedSize(70,70);
       root_yx ->setFixedSize(70,70);


       sinh->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       cosh->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       tanh->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       n_fact->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       sin ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       cos ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       tan ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       contant_pi ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       exp ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       ln ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       log->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       root_3x ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       power_2 ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       power_3->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       power_y ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");
       root_yx ->setStyleSheet("QPushButton { border: 1px solid gray;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}");

       grid_engineer = new QGridLayout(this);
       //grid_layout->setSpacing(20);
       grid_engineer->setSpacing(10);
       grid_engineer->addWidget(sinh,0,0);
       grid_engineer->addWidget(cosh,0,1);
       grid_engineer->addWidget(tanh,0,2);
       grid_engineer->addWidget(n_fact,0,3);
       grid_engineer->addWidget(sin,1,0);
       grid_engineer->addWidget(cos,1,1);
       grid_engineer->addWidget(tan,1,2);
       grid_engineer->addWidget(contant_pi,1,3);
       grid_engineer->addWidget(exp,2,0);
       grid_engineer->addWidget(ln,2,1);
       grid_engineer->addWidget(log,2,2);
       grid_engineer->addWidget(root_3x,2,3);
       grid_engineer->addWidget(power_2,3,0);
       grid_engineer->addWidget(power_3,3,1);
       grid_engineer->addWidget(power_y,3,2);
       grid_engineer->addWidget(root_yx,3,3);

       engineer_calculator->setLayout(grid_engineer);

       final = new QHBoxLayout(this);
       final->addWidget(engineer_calculator);
       final->addWidget(default_calculator);
       vertical_layout->addLayout(final);


       grid_default->setSpacing(5);
       grid_engineer->setSpacing(5);

       this->setMaximumHeight(500);
       engineer_calculator->setVisible(false);
       cent_wgt->setLayout(vertical_layout);
       setCentralWidget(cent_wgt);



    }





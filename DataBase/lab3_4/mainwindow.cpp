#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect_database();
    create_bars();
    create_calendars();

    connect(ui->pushButton_rentCar,SIGNAL(clicked()),this,SLOT(rent_car()));
    connect(ui->pushButton_addcar,SIGNAL(clicked()),this,SLOT(add_car()));
    connect(ui->pushButton_change,SIGNAL(clicked()),this,SLOT(change_parameters()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rent_car()
{
    if(query->exec(QString("INSERT INTO orders VALUES('%1','%2','%3')").arg(ui->comboBoxCars->currentData().toString()).arg(ui->lineFio->text()).arg(ui->calendar_rentCar->selectedDate().toString("yyyy-MM-dd"))))
        QMessageBox::information(this,"info","Order successfully added");
    else
        QMessageBox::warning(this,"warning","Order not added");
}

void MainWindow::add_car()
{
    if(query->exec(QString("INSERT INTO cars VALUES('%1','%2','%3',%4)").arg(ui->lineEdit_id->text()).arg(ui->lineEdit_colour->text()).arg(ui->lineEdit_model->text()).arg(ui->lineEdit_rent->text().toInt())))
        QMessageBox::information(this,"info","Car successfully added");
    else
        QMessageBox::warning(this,"warning","Car not added");
}

void MainWindow::change_parameters()
{
    if(query->exec(QString("select change_pars(%1,%2,%3,%4)").arg(ui->lineEdit_license->text().toInt()).arg(ui->lineEdit_t_o->text().toInt()).arg(ui->lineEdit_wheels->text().toInt()).arg(ui->lineEdit_insurance->text().toInt())))
        QMessageBox::information(this,"info","Parameters successfuly changed");
    else
        QMessageBox::warning(this,"warning","Parameters successfuly changed");
}
void MainWindow::connect_database()
{
    query = new QSqlQuery(db);

    db.setHostName("195.19.32.74");
    db.setPort(5432);
    db.setDatabaseName("fn1132_2019");
    db.setUserName("student");
    db.setPassword("bmstu");

    if(db.open())
    {
        QMessageBox::information(this,"info","conntecter successfully");
        query->exec("select set_today()");
        ui->calendar_rentCar->setMinimumDate(ui->calendar_rentCar->selectedDate());
        set_today_outlays();
    }
    else
        QMessageBox::warning(this,"warning","conntecter unsuccessfully");

}

void MainWindow::create_bars()
{
    QAction *next_day = new QAction("Next day",this);
    connect(next_day,SIGNAL(triggered()),this,SLOT(next_day_slot()));
    ui->toolBar->addAction(next_day);
}

void MainWindow::next_day_slot()
{
    query->exec("select next_day()");
    set_today_outlays();
    //query->exec("select to_char((select * from local_time),'dd/MM/yyyy')");
    query->exec("select * from local_time");
    query->first();
    ui->calendar_rentCar->setMinimumDate(query->value(0).toDate());
}

void MainWindow::set_today_outlays()
{
    model_outlays.setQuery("select id_outlay as номер, outlay as затраты, service_type as услуга from outlays join parameters on outlays.outlay=parameters.price where outlay_date=(select * from local_time)");
    ui->tableOutlays->setModel(&model_outlays);
    model_rent.setQuery("select id as номер, colour as цвет, model as модель,driver as водитель,rent as доход from orders join cars on orders.id_order = cars.id where order_date=(select * from local_time)");
    ui->tableRent->setModel(&model_rent);
    query->exec("select to_char((select * from local_time),'dd/MM/yyyy')");
    model_tech.setQuery("select id_maintenance as car_id,((select day_count from parameters where service_type='t_o')-t_o) as to, ((select day_count from parameters where service_type='wheels')-wheels) as wheels, ((select day_count from parameters where service_type='insurance')-insurance) as insurance, ((select day_count from parameters where service_type='license')-license) as license from maintenances");
    ui->tableTech->setModel(&model_tech);
    query->first();
    ui->statusbar->showMessage(query->value(0).toString());
}


void MainWindow::create_calendars()
{
    connect(ui->calendarFirst,SIGNAL(selectionChanged()),this,SLOT(get_first_date()));
    connect(ui->calendarSecond,SIGNAL(selectionChanged()),this,SLOT(get_second_date()));

    connect(ui->calendar_rentCar,SIGNAL(selectionChanged()),this,SLOT(calendar_add_rentaable_cars()));
}

void MainWindow::get_first_date()
{
    first_date = ui->calendarFirst->selectedDate().toString("yyyy-MM-dd");
    ui->calendarSecond->setMinimumDate(ui->calendarFirst->selectedDate());
    model_tab2.setQuery(QString("select id_order as номер, rent as доход, sum(outlay) as убыток, (rent-sum(outlay)) as прибыль from (select id_order,sum(rent) as rent from orders left join cars on cars.id = orders.id_order where order_date >= '%1'::date and order_date <= '%2'::date group by id_order) as foo left join (select * from outlays where outlay_date >= '%1'::date and outlay_date <= '%2'::date) as foo2 on foo.id_order = foo2.id_outlay group by id_order, rent").arg(first_date).arg(second_date));
    qDebug() << first_date << "\t" << second_date;
    ui->tableCash->setModel(&model_tab2);
}

void MainWindow::get_second_date()
{
    second_date = ui->calendarSecond->selectedDate().toString("yyyy-MM-dd");
    ui->calendarFirst->setMaximumDate(ui->calendarSecond->selectedDate());
    model_tab2.setQuery(QString("select id_order as номер, rent as доход, sum(outlay) as убыток, (rent-sum(outlay)) as прибыль from (select id_order,sum(rent) as rent from orders left join cars on cars.id = orders.id_order where order_date >= '%1'::date and order_date <= '%2'::date group by id_order) as foo left join (select * from outlays where outlay_date >= '%1'::date and outlay_date <= '%2'::date) as foo2 on foo.id_order = foo2.id_outlay group by id_order, rent").arg(first_date).arg(second_date));
    ui->tableCash->setModel(&model_tab2);
}


void MainWindow::calendar_add_rentaable_cars()
{
    query->exec(QString("select id from cars where id not in (select distinct id_order from orders where order_date = '%1')").arg(ui->calendar_rentCar->selectedDate().toString("yyyy-MM-dd")));

    ui->comboBoxCars->clear();

    QSqlRecord rec = query->record();
    int num = rec.count();
    query->first();

    ui->comboBoxCars->addItem(query->value(0).toString());

            while(query->next())
                    ui->comboBoxCars->addItem(query->value(0).toString());

}

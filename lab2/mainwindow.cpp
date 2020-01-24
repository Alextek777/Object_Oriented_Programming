#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    query = new QSqlQuery(data_base);
    highlighter = new CustomHighlighter("C++",ui->textEdit);
    highlighter->setDocument(ui->textEdit->document());

    qApp->installEventFilter(this);

    connect(ui->button_connect,SIGNAL(clicked()),this,SLOT(connect_database()));
    connect(ui->list_view, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(load_table()));
    connect(ui->button_run,SIGNAL(clicked()),this,SLOT(run_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


    void MainWindow::run_button_clicked()
    {

        if(query->exec(ui->textEdit->toPlainText()))
        {
            ui->table_view->setModel(&table_model);
            load_dataDase_stringModel();
            ui->text_error->setText("Querry successfully loaded!");
            if(std::find(command_history.begin(),command_history.end(),QString(ui->textEdit->toPlainText())) == command_history.end());
                command_history.push_back(QString(ui->textEdit->toPlainText()));

                QSqlRecord rec;
                int num;
                QString output = "";
                rec = query->record();
                    if(query->isSelect())
                    {
                        num = rec.count();
                        output += "\n";
                        for(int i=0;i<num;i++)
                        {
                           // rec.value(i).toString().toStdString();
                            output += rec.fieldName(i) +="\n";
                        }
                            output += "\n";
                        while(query->next())
                        {
                            for(int i=0;i<num;i++)
                                output += query->value(i).toString() += "\n";
                                output += "\n";
                        }
                    }
                    ui->text_error->setText(output);
            switch (history_index) {
            case 1:
                ui->textBrowser_1->setText(ui->textEdit->toPlainText());
                history_index++;
                break;
            case 2:
                ui->textBrowser_2->setText(ui->textEdit->toPlainText());
                history_index++;
                break;
            case 3:
                ui->textBrowser_3->setText(ui->textEdit->toPlainText());
                history_index++;
                break;
            case 4:
                ui->textBrowser_4->setText(ui->textEdit->toPlainText());
                history_index = 1;
                break;
            }
        }
        else
            ui->text_error->setText(query->lastError().text());
    }


void MainWindow::connect_database()
{
    data_base.setHostName(ui->line_ip->text());
    data_base.setPort(ui->line_port->text().toInt());
    data_base.setDatabaseName(ui->line_databaseName->text());
    data_base.setUserName(ui->line_login->text());
    data_base.setPassword(ui->line_password->text());

    if(data_base.open())
    {
        QMessageBox::information(this,tr("Info"),tr("Database sucessfully connected!"));
        load_dataDase_stringModel();
    }
    else
        QMessageBox::warning(this,tr("Error"),tr("couldn`t connect to database!"));
}

void MainWindow::load_table()
{
    QString tableName = ui->list_view->currentIndex().data().toString();
    table_model.setQuery(QString("SELECT * FROM %1").arg(tableName));
    ui->table_view->setModel(&table_model);
}



bool MainWindow::eventFilter(QObject *obj,QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key_event = static_cast<QKeyEvent*>(event);
        if(key_event->key() == Qt::Key_Down && !command_history.isEmpty() && command_history.size() > current_command)
        {
            ui->textEdit->setText(command_history[current_command]);
            current_command++;
        }
        if(key_event->key() == Qt::Key_Up && !command_history.isEmpty() && current_command > 0)
        {
            current_command--;
            ui->textEdit->setText(command_history[current_command]);
        }
    }
    QObject::eventFilter(obj,event);
}

void MainWindow::load_dataDase_stringModel()
{
    list_table_names = data_base.tables();
    list_model.setStringList(list_table_names);
    ui->list_view->setModel(&list_model);
}

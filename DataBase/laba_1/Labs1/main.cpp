#include <QCoreApplication>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <iomanip>

using namespace std;



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");   //QPSQL
    //db.set
    QSqlQuery dbQuerry(db);
    QSqlRecord rec;
    //QSqlRecord rec = dbQuerry.record();

    /*
    db.setDatabaseName("fn1132_2019");
    db.setHostName("195.19.32.75");
    db.setPort(5432);
    db.setUserName("student");
    db.setPassword("bmstu");
    */
    db.open();

    if(!db.open())
    {
        qDebug()  << db.lastError().text();
        return a.exec();
    }

    cout << "database opened!!!" << endl;
    if(!dbQuerry.exec("PRAGMA foreign_keys = ON"))
    qDebug() << dbQuerry.lastError();



//    dbQuerry.exec("CREATE TABLE fn11_32(id INT NOT NULL AUTO_INCREMENT,mark INT,name VARCHAR(12),age INT);");

//    if(!dbQuerry.isActive())
//    {
//        cout << "db isn`t active!" <<endl;
//    }
//        else
//    {
//        cout << "db is active!" <<endl;
//        dbQuerry.exec("INSERT INTO fn11_32(num,name,age),   VALUES(1, 'Tektumanidze', 18),(2, 'Pokhilov', 20), (3, 'Popkova', 18);");
//        dbQuerry.exec("SELECT * FROM fn11_32");

//    }

    //cout << "db is active!" <<endl;
    //dbQuerry.exec("INSERT INTO fn11_32(num,name,age),   VALUES(1, 'Tektumanidze', 18),(2, 'Pokhilov', 20), (3, 'Popkova', 18);");
    //dbQuerry.exec("SELECT * FROM fn11_32");

    int num=0;
    //
    bool ending = false;
    string stdCommand;
    QString Qcommand;
    do
    {
        std::getline(std::cin,stdCommand);
        Qcommand = QString::fromUtf8(stdCommand.c_str());

        if(!dbQuerry.exec(Qcommand))
        {
            if(stdCommand == "close")
                ending = true;
            else
            qDebug() << dbQuerry.lastError().text();
        }/*
                                                        while(dbQuerry.isSelect() && dbQuerry.next() && !ending)
                                                        {
                                                            qDebug() << dbQuerry.record();
                                                        }*/

        rec = dbQuerry.record();
            if(dbQuerry.isSelect())
            {
                num = rec.count();
                std::cout << setw(10);
                for(int i=0;i<num;i++)
                {
                   // rec.value(i).toString().toStdString();
                    std::cout << rec.fieldName(i).toStdString() << setw(10);
                }
                    std::cout << std::endl;
                while(dbQuerry.next())
                {
                    for(int i=0;i<num;i++)
                        std::cout<< dbQuerry.value(i).toString().toStdString() << setw(10);
                        std::cout << std::endl;
                }
            }



        }while(!ending);





    //dbQuerry.exec("DROP TABLE fn11_32C");
    //dbQuerry.exec("CREATE TABLE fn11_32c(id INT NUT NULL, name VARCHAR(30),age INT)");
    //dbQuerry.exec("INSERT INTO fn11_32c(id,name,age) VALUES(1,'alex',17),(2,'misha',21),(3,'miran',19)");

       /* if(!dbQuerry.exec("SELECT * FROM fn11_32c"))
        {
    qDebug() << dbQuerry.lastError().text();
        }
    while(dbQuerry.isSelect() && dbQuerry.next())
    {
        qDebug() << dbQuerry.record();
    }*/

    //dbQuerry.exec("SELECT * FROM fn11_32");
    dbQuerry.exec("DROP TABLE fn11_32C");

/*
CREATE TABLE student(name VARCHAR[10],number VARCHAR[10], FOREIGN KEY(number) REFERENCES groups(number))
INSERT INTO groups(dep,number) VALUES ('alex','fn1132'),('Lev','fn1133'),('someone','fn1134')
INSERT INTO student(name,number) VALUES ('tektumanidze','fn1132'),('Pokhilov','fn1133')
INSERT INTO student(name,number) VALUES ('tektumanidze','fn1132'),('Poxilov','fn1133'),('leviy','fn1135')
*/

db.close();

    return 0;
}

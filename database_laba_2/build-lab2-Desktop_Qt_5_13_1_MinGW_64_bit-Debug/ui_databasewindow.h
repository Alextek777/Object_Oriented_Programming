/********************************************************************************
** Form generated from reading UI file 'databasewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEWINDOW_H
#define UI_DATABASEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DatabaseWindow)
    {
        if (DatabaseWindow->objectName().isEmpty())
            DatabaseWindow->setObjectName(QString::fromUtf8("DatabaseWindow"));
        DatabaseWindow->resize(800, 600);
        centralwidget = new QWidget(DatabaseWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 160, 295, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        DatabaseWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DatabaseWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        DatabaseWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DatabaseWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DatabaseWindow->setStatusBar(statusbar);

        retranslateUi(DatabaseWindow);

        QMetaObject::connectSlotsByName(DatabaseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DatabaseWindow)
    {
        DatabaseWindow->setWindowTitle(QCoreApplication::translate("DatabaseWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("DatabaseWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DatabaseWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DatabaseWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseWindow: public Ui_DatabaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEWINDOW_H

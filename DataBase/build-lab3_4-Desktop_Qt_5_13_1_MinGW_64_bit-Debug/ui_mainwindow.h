/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableOutlays;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableView *tableRent;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QCalendarWidget *calendarFirst;
    QCalendarWidget *calendarSecond;
    QTableView *tableCash;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QTableView *tableTech;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineFio;
    QLabel *label_5;
    QCalendarWidget *calendar_rentCar;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QComboBox *comboBoxCars;
    QPushButton *pushButton_rentCar;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_id;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_colour;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *lineEdit_model;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *lineEdit_rent;
    QPushButton *pushButton_addcar;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLineEdit *lineEdit_license;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_16;
    QLineEdit *lineEdit_t_o;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_17;
    QLineEdit *lineEdit_wheels;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QLineEdit *lineEdit_insurance;
    QPushButton *pushButton_change;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1148, 581);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tableOutlays = new QTableView(tab);
        tableOutlays->setObjectName(QString::fromUtf8("tableOutlays"));

        verticalLayout->addWidget(tableOutlays);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        tableRent = new QTableView(tab);
        tableRent->setObjectName(QString::fromUtf8("tableRent"));

        verticalLayout_2->addWidget(tableRent);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        calendarFirst = new QCalendarWidget(tab_2);
        calendarFirst->setObjectName(QString::fromUtf8("calendarFirst"));
        calendarFirst->setStyleSheet(QString::fromUtf8("QCalendarWidget QAbstractItemView:enabled \n"
"  {\n"
"  	selection-background-color: rgb(64, 64, 64); \n"
"  	selection-color: rgb(3, 255, 255); \n"
"  }"));

        horizontalLayout_4->addWidget(calendarFirst);

        calendarSecond = new QCalendarWidget(tab_2);
        calendarSecond->setObjectName(QString::fromUtf8("calendarSecond"));
        calendarSecond->setStyleSheet(QString::fromUtf8("QCalendarWidget QAbstractItemView:enabled \n"
"  {\n"
"  	selection-background-color: rgb(64, 64, 64); \n"
"  	selection-color: rgb(3, 255, 255); \n"
"  }"));

        horizontalLayout_4->addWidget(calendarSecond);


        verticalLayout_3->addLayout(horizontalLayout_4);

        tableCash = new QTableView(tab_2);
        tableCash->setObjectName(QString::fromUtf8("tableCash"));
        tableCash->setStyleSheet(QString::fromUtf8("QCalendarWidget QToolButton {\n"
"  	height: 60px;\n"
"  	width: 150px;\n"
"  	color: white;\n"
"  	font-size: 24px;\n"
"  	icon-size: 56px, 56px;\n"
"  	background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);\n"
"  }\n"
"  QCalendarWidget QMenu {\n"
"  	width: 150px;\n"
"  	left: 20px;\n"
"  	color: white;\n"
"  	font-size: 18px;\n"
"  	background-color: rgb(100, 100, 100);\n"
"  }\n"
"  QCalendarWidget QSpinBox { \n"
"  	width: 150px; \n"
"  	font-size:24px; \n"
"  	color: white; \n"
"  	background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333); \n"
"  	selection-background-color: rgb(136, 136, 136);\n"
"  	selection-color: rgb(255, 255, 255);\n"
"  }\n"
"  QCalendarWidget QSpinBox::up-button { subcontrol-origin: border;  subcontrol-position: top right;  width:65px; }\n"
"  QCalendarWidget QSpinBox::down-button {subcontrol-origin: border; subcontrol-position: bottom right;  width:65px;}\n"
"  QCalendarWidget QSpinBox::up-arrow { width:56p"
                        "x;  height:56px; }\n"
"  QCalendarWidget QSpinBox::down-arrow { width:56px;  height:56px; }\n"
"   \n"
"  /* header row */\n"
"  QCalendarWidget QWidget { alternate-background-color: rgb(128, 128, 128); }\n"
"   \n"
"  /* normal days */\n"
"  QCalendarWidget QAbstractItemView:enabled \n"
"  {\n"
"  	font-size:24px;  \n"
"  	color: rgb(180, 180, 180);  \n"
"  	background-color: black;  \n"
"  	selection-background-color: rgb(64, 64, 64); \n"
"  	selection-color: rgb(0, 255, 0); \n"
"  }\n"
"   \n"
"  /* days in other months */\n"
"  /* navigation bar */\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar\n"
"{ \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333); \n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:disabled \n"
"{ \n"
"color: rgb(64, 64, 64); \n"
"}"));

        verticalLayout_3->addWidget(tableCash);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        tableTech = new QTableView(tab_2);
        tableTech->setObjectName(QString::fromUtf8("tableTech"));

        verticalLayout_4->addWidget(tableTech);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_9 = new QVBoxLayout(tab_3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineFio = new QLineEdit(tab_3);
        lineFio->setObjectName(QString::fromUtf8("lineFio"));

        horizontalLayout_6->addWidget(lineFio);


        verticalLayout_6->addLayout(horizontalLayout_6);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        calendar_rentCar = new QCalendarWidget(tab_3);
        calendar_rentCar->setObjectName(QString::fromUtf8("calendar_rentCar"));
        calendar_rentCar->setStyleSheet(QString::fromUtf8("QCalendarWidget QAbstractItemView:enabled \n"
"  {\n"
"  	selection-background-color: rgb(64, 64, 64); \n"
"  	selection-color: rgb(3, 255, 255); \n"
"  }"));

        verticalLayout_6->addWidget(calendar_rentCar);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        comboBoxCars = new QComboBox(tab_3);
        comboBoxCars->setObjectName(QString::fromUtf8("comboBoxCars"));

        horizontalLayout_7->addWidget(comboBoxCars);


        verticalLayout_6->addLayout(horizontalLayout_7);

        pushButton_rentCar = new QPushButton(tab_3);
        pushButton_rentCar->setObjectName(QString::fromUtf8("pushButton_rentCar"));

        verticalLayout_6->addWidget(pushButton_rentCar);


        horizontalLayout_12->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_id = new QLineEdit(tab_3);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        horizontalLayout_8->addWidget(lineEdit_id);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);

        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        lineEdit_colour = new QLineEdit(tab_3);
        lineEdit_colour->setObjectName(QString::fromUtf8("lineEdit_colour"));

        horizontalLayout_9->addWidget(lineEdit_colour);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 3);

        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        lineEdit_model = new QLineEdit(tab_3);
        lineEdit_model->setObjectName(QString::fromUtf8("lineEdit_model"));

        horizontalLayout_10->addWidget(lineEdit_model);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 3);

        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(7);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, -1, -1, 0);
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_11->addWidget(label_11);

        lineEdit_rent = new QLineEdit(tab_3);
        lineEdit_rent->setObjectName(QString::fromUtf8("lineEdit_rent"));

        horizontalLayout_11->addWidget(lineEdit_rent);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 3);

        verticalLayout_7->addLayout(horizontalLayout_11);

        pushButton_addcar = new QPushButton(tab_3);
        pushButton_addcar->setObjectName(QString::fromUtf8("pushButton_addcar"));

        verticalLayout_7->addWidget(pushButton_addcar);


        horizontalLayout_12->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        lineEdit_license = new QLineEdit(tab_3);
        lineEdit_license->setObjectName(QString::fromUtf8("lineEdit_license"));

        horizontalLayout_13->addWidget(lineEdit_license);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 3);

        verticalLayout_8->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_14->addWidget(label_16);

        lineEdit_t_o = new QLineEdit(tab_3);
        lineEdit_t_o->setObjectName(QString::fromUtf8("lineEdit_t_o"));

        horizontalLayout_14->addWidget(lineEdit_t_o);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 3);

        verticalLayout_8->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_15->addWidget(label_17);

        lineEdit_wheels = new QLineEdit(tab_3);
        lineEdit_wheels->setObjectName(QString::fromUtf8("lineEdit_wheels"));

        horizontalLayout_15->addWidget(lineEdit_wheels);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 3);

        verticalLayout_8->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_16->addWidget(label_18);

        lineEdit_insurance = new QLineEdit(tab_3);
        lineEdit_insurance->setObjectName(QString::fromUtf8("lineEdit_insurance"));

        horizontalLayout_16->addWidget(lineEdit_insurance);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 3);

        verticalLayout_8->addLayout(horizontalLayout_16);

        pushButton_change = new QPushButton(tab_3);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));

        verticalLayout_8->addWidget(pushButton_change);


        horizontalLayout_12->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_12);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1148, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\205\320\276\320\264\321\213 \320\275\320\260 \321\201\320\265\320\263\320\276\320\264\320\275\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264 \320\267\320\260 \321\201\320\265\320\263\320\276\320\264\320\275\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264\321\200\320\260\321\201\321\205\320\276\320\264 \320\267\320\260 \321\201\321\200\320\276\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\264\320\275\320\265\320\271 \320\264\320\276 \321\202\320\265\321\205. \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\244.\320\230.\320\236", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\260\321\210\320\270\320\275\321\203", nullptr));
        pushButton_rentCar->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\260\320\262\321\202\320\276:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\260\320\262\321\202\320\276:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\220\321\200\320\265\320\275\320\264\320\260/\320\264\320\265\320\275\321\214:", nullptr));
        pushButton_addcar->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\321\206\320\265\320\275\320\267\320\270\321\217:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\321\205. \320\276\320\261\321\201\320\273.:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\260 \320\272\320\276\320\273\320\265\321\201:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\272\320\260:", nullptr));
        pushButton_change->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Page", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QTreeView>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>
#include <QFileDialog>
#include <locale>
#include <QStandardItemModel>
#include <QXmlQuery>
//#include <QtXml/QDomDocument>
//#include <QFile>
#include <QDebug>
//#include <QXmlInputSource>
//#include <QXmlSimpleReader>
#include <QTreeView>


//#include <QItemSelectionModel>
#include <QStringListModel>
#include "contexmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private://widgets
    QMenu *my_menu;
    ContexMenu *my_contex_menu;
    QTreeView *tree_view;
    QPushButton *ok_button,*load_button;
    QTextEdit *text_edit;
    QWidget *central_widget;


private://variables
    QStandardItemModel model;
    QString str_querry;
    QXmlQuery xml_querry;
    QStringList file_path_list;
    QModelIndex active_index;



public slots:
    bool open_slot();
    bool close_slot();
    void exit_slot();
    bool ok_clicked();
    bool load_clicked();
    bool close_current_file();

    void cell_triggered();
    void ContextMenu(QPoint);
    void active();
    void close_current_cell();



private://functions
    void set_menu();
    void set_widgets();
    bool loadXml();

};

#endif // MAINWINDOW_H

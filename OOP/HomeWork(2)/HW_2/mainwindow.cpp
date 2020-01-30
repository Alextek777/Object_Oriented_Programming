#include "mainwindow.h"
#include <QApplication>
#include "xmlhandlers.h"
#include <QMessageBox>
#include <QListWidget>
#include <QDockWidget>
#include <QFont>



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    setWindowIcon(QPixmap(":/images/img/xml.png"));
    resize(700,700);

    set_menu();
    set_widgets();
}

MainWindow::~MainWindow()
{

}

bool MainWindow::open_slot()
{
    return loadXml();
}


bool MainWindow::close_slot()
{
    model.clear();
    file_path_list.clear();
    tree_view->setModel(&model);
    return true;
}

void MainWindow::exit_slot()
{
    QApplication::quit();
}

bool MainWindow::close_current_file()
{
    auto idx = tree_view->currentIndex();
    while (idx.parent().isValid())
    {
        idx = idx.parent();
    }
    return(model.removeRow(idx.column()));
}

void MainWindow::set_menu()
{
    my_menu = new QMenu("&File");

    QAction *open_action = new QAction("Open XML file",this);
    open_action->setText("Open");
    open_action->setShortcut(QKeySequence("CTRL+O"));
    open_action->setToolTip("open Document");
    open_action->setStatusTip("Open and parse XML documents1");
    open_action->setWhatsThis("Open and parse XML documents2");
    open_action->setIcon(QPixmap(":/images/img/open.png"));
    connect(open_action,SIGNAL(triggered()),this,SLOT(open_slot()));
    my_menu->addAction(open_action);

    QAction *close_action = new QAction("close XML file",this);
    close_action->setText("close all");
    close_action->setShortcut(QKeySequence("CTRL+X"));
    close_action->setToolTip("close Documents");
    close_action->setStatusTip("close documents1");
    close_action->setWhatsThis("close documents2");
    close_action->setIcon(QPixmap(":/images/img/close.jpg"));
    connect(close_action,SIGNAL(triggered()),this,SLOT(close_slot()));
    my_menu->addAction(close_action);
    my_menu->addSeparator();

    QAction *my_exit = new QAction("exit file",this);
    my_exit->setText("exit");
    my_exit->setShortcut(QKeySequence("CTRL+Q"));
    my_exit->setToolTip("exit Documents");
    my_exit->setStatusTip("exit documents1");
    my_exit->setWhatsThis("exit documents2");
    my_exit->setIcon(QPixmap(":/images/img/exit.jpg"));
    connect(my_exit,SIGNAL(triggered()),this,SLOT(exit_slot()));
    my_menu->addAction(my_exit);

    menuBar()->addMenu(my_menu);
    my_contex_menu = new ContexMenu;

}

    void MainWindow::set_widgets()
    {
        central_widget = new QWidget(this);
        QBoxLayout *vertical_layout = new QBoxLayout(QBoxLayout::TopToBottom);
        QBoxLayout *horizontal_layout = new QBoxLayout(QBoxLayout::LeftToRight);
        QBoxLayout *vecrical_for_buttons = new QBoxLayout(QBoxLayout::TopToBottom);

        tree_view = new QTreeView(this);
        text_edit = new QTextEdit("Enter commands here",this);
        ok_button = new QPushButton("OK",this);
        load_button = new QPushButton("Load Querry",this);

        vertical_layout->addWidget(tree_view);
        horizontal_layout->addWidget(text_edit);
        vecrical_for_buttons->addWidget(ok_button);
        vecrical_for_buttons->addWidget(load_button);
        horizontal_layout->addLayout(vecrical_for_buttons);
        vertical_layout->addLayout(horizontal_layout,1);

        central_widget->setLayout(vertical_layout);



        this->setCentralWidget(central_widget);


        //------------------------widget settings-------------------------------
        text_edit->setMaximumHeight(50);
        connect(ok_button,SIGNAL(clicked()),this,SLOT(ok_clicked()));
        connect(load_button,SIGNAL(clicked()),this,SLOT(load_clicked()));

        //model triggered connection
        connect(tree_view,SIGNAL(clicked()),this,SLOT(cell_triggered()));
        tree_view->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(tree_view, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ContextMenu(QPoint)));
    }

    bool MainWindow::loadXml()
    {
        setlocale(LC_ALL,"russian");
        QFile *file;
        QXmlInputSource *source;
        QXmlSimpleReader reader;

        FoodHandler handler(&model);
        QString file_name = QFileDialog::getOpenFileName();
        file_path_list.push_back(file_name);
        file = new QFile(file_name);
        source = new QXmlInputSource(file);
        reader.setContentHandler(&handler);
        reader.parse(source);


        tree_view->setModel(&model);
        qDebug() << "load complited!";
        return true;
    }

    bool MainWindow::ok_clicked()
    {
        if(file_path_list.isEmpty())
        {
            QMessageBox::warning(this,"Error message","there is no XML file to evaluate querry!");
            return false;
        }
        str_querry = text_edit->toPlainText();
        auto idx = tree_view->currentIndex();

        if(active_index.isValid()){idx = active_index;}
        else
        {
            emit active();
            idx = active_index;
        }
        if(!idx.isValid())
        {
            QMessageBox::warning(this,"Error message","choose xml file to evaluate querry!");
            return false;
        }
        QFile xml_file(file_path_list[idx.row()]);
        if(xml_file.open(QIODevice::ReadOnly))
        {
            xml_querry.bindVariable("inputDocument",&xml_file);
            xml_querry.setQuery(str_querry);
            if(!xml_querry.isValid())
            {
                QMessageBox::warning(this,"querry is Invalid!","querry is Invalid!");
                return false;
            }
            QString str_output;
            QStringList listOutput;
            if(!xml_querry.evaluateTo(&listOutput))
            {
                QMessageBox::warning(this,"error message","can`t evaluate querry!");
                return false;
            }
            qDebug() << "valid querry!";
            xml_file.close();

            QListWidget* list_widget = new QListWidget;
            for (auto it : listOutput)
            {
                list_widget->addItem(it);
            }
            QListView* list_view = new QListView;
            list_view->setModel(list_widget->model());
            QDockWidget* doc = new QDockWidget;
            doc->setMinimumSize(1000,700);
            doc->setWidget(list_view);
            doc->setWindowTitle("XQuery");
            doc->show();
        }
    }

    bool MainWindow::load_clicked()
    {
       QFile xq_file(":/XQuerry_file/myQuerry.xq");
       if(xq_file.open(QIODevice::ReadOnly))
       {
           str_querry = xq_file.readAll();
           xq_file.close();
           text_edit->setText(str_querry);
           return true;
       }
           QMessageBox::warning(this,"Can`t open querry file for reading","Can`t open querry file for reading");
           return false;
    }

    void MainWindow::cell_triggered()
    {
        QModelIndex idx = tree_view->currentIndex();
        while (idx.parent().isValid())
        {
            idx = idx.parent();
        }
        QFont font;
        font.setBold(true);
        tree_view->setFont(font);
    }

    void MainWindow::ContextMenu(QPoint pos)
    {
        auto idx = tree_view->currentIndex();
        auto parent = idx.parent();
        if(!parent.isValid())
        {
            QMenu* menu = new QMenu(this);
            QAction* close = new QAction("close", this);
            connect(close, SIGNAL(triggered()), this, SLOT(close_current_cell()));
            menu->addAction(close);
            menu->popup(tree_view->viewport()->mapToGlobal(pos));
            QAction *aktiv = new QAction("active",this);
            menu->addAction(aktiv);
            connect(aktiv,SIGNAL(triggered()),this,SLOT(active()));
           // TextEdit->setText("\n");
        }
    }

    void MainWindow::active()
    {
        QFont a;
        if(active_index.isValid())
        {
            a.setBold(false);
            tree_view->model()->setData(active_index,a,Qt::FontRole);
        }
        auto idx = tree_view->currentIndex();
        auto parent = idx.parent();
        while(parent.isValid())
        {
            idx = parent;
            parent = parent.parent();
        }
       if(!parent.isValid())
           {
               tree_view->selectAll();
               tree_view->reset();
               a.setBold(true);
               tree_view->model()->setData(idx,a,Qt::FontRole);
               active_index = idx;
            }
    }

    void MainWindow::close_current_cell()
    {
        QModelIndex idx = tree_view->currentIndex();
        while(idx.parent().isValid())
        {
            idx = idx.parent();
        }

        tree_view->model()->removeRow(idx.row());
    }

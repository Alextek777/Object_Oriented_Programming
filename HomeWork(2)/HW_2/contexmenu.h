#ifndef CONTEXMENU_H
#define CONTEXMENU_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QMenu>
#include <QContextMenuEvent>

class ContexMenu : public QTextEdit
{
    Q_OBJECT
private:
    QMenu *menu;

protected:
    virtual void contextMenuEvent(QContextMenuEvent *p){menu->exec(p->globalPos ());}

public:
    ContexMenu(QWidget * parent = 0) : QTextEdit(parent)
    {
        setReadOnly(true);
        menu = new QMenu("Contex Menu",this);
        QAction *delete_action = new QAction("close current file");
        delete_action->setText("close current file");
        connect(delete_action,SIGNAL(triggered()),this,SLOT(close_current_file()));
        menu->addAction(delete_action);
    }

};

#endif // CONTEXMENU_H

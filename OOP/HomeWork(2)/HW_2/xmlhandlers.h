#ifndef XMLHANDLERS_H
#define XMLHANDLERS_H
#include <QXmlDefaultHandler>
#include <QStandardItemModel>
#include <QtCore>
#include <QtGui>
#include <QVector>



class FoodHandler : public QXmlDefaultHandler
{
private:
    QString str_text;
    QStandardItemModel *model;
    QStandardItem *allFather;
    QStandardItem *parentItem;
    QStandardItem *item;
    QString tag_name,tag_info;
    int row=0;

public:
    explicit FoodHandler(QStandardItemModel *root) : model(root)
    {
        parentItem = model->invisibleRootItem();
        tag_name = "Listring";
        item = new QStandardItem(tag_name);
        parentItem->appendRow(item);
        parentItem=item;
        allFather=parentItem;
        model->setColumnCount(2);
        setlocale(LC_ALL,"Russian");
    }

    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts) override;
    bool characters(const QString &ch) override;
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName) override;
    bool fatalError(const QXmlParseException &exception) override;
};


#endif // XMLHANDLERS_H


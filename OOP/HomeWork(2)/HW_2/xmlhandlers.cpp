#include "xmlhandlers.h"
#include <iostream>
#include <QDebug>
#include <locale>
#include <QErrorMessage>
#include <QMessageBox>




bool FoodHandler::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    tag_name = localName;
    if(tag_name == "array")
    {
        item = new QStandardItem(tag_name);
        parentItem->appendRow(item);
        parentItem = item;
        row++;
    }
    //qDebug() << "tag Name : " << tag_name;
    return true;
}

bool FoodHandler::characters(const QString &ch)
{
    tag_info = ch;
    //qDebug() << "tag info : " << tag_info;
    return true;
}

 bool FoodHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
 {
     if(tag_name == localName && tag_name != "Name")
     {
         //qDebug() << "adding tag :   name :" << tag_name << "     info : " << tag_info;
         QList<QStandardItem *> item_list;
         item = new QStandardItem(tag_name);
         item_list.append(item);
         item = new QStandardItem(tag_info);
         item_list.append(item);
         parentItem->appendRow(item_list);
     }
     else if(tag_name == "Name"){parentItem->clearData();parentItem->setText(tag_info);}
     if(localName == "array")parentItem = parentItem->parent();
     return true;
 }

 bool FoodHandler::fatalError(const QXmlParseException &exception)
 {
     QMessageBox msg;
     msg.critical(0,"Error","An error has occured while reading xml file!");
     msg.setFixedSize(500,200);
     msg.show();
     return true;
 }

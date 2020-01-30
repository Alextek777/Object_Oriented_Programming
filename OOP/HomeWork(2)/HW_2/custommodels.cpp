#include "custommodels.h"


TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parent)//saving data and parent
{
    parentItem = parent;
    itemData = data;
}

TreeItem::~TreeItem()//destructor
{
    qDeleteAll(childItems);
}

void TreeItem::appendChild(TreeItem *item)//adding child item
{
    childItems.append(item);
}

TreeItem *TreeItem::child(int row)//returns children by column index children items
{
    return childItems.value(row);
}

int TreeItem::childCount() const//returns number of children
{
    return childItems.count();
}

int TreeItem::row() const//The TreeModel uses this function to determine the number of rows that exist for a given parent item.
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

int TreeItem::columnCount() const//The number of columns of data in the item is trivially returned by the columnCount() function.
{
    return itemData.count();
}

QVariant TreeItem::data(int column) const//returns data from item by column index
 {
     return itemData.value(column);
 }

TreeItem *TreeItem::parent()//returns parent of this Item
{
    return parentItem;
}

//------------------------------------------------------------------------------------------------------


TreeModel::TreeModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Title" << "Summary";
    rootItem = new TreeItem(rootData);

    QString file_name = QFileDialog::getOpenFileName();
    file = new QFile(file_name);
    source = new QXmlInputSource(file);



    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "couldn`t open file!";

    else
        setupModelData(data.split(QString("\n")), rootItem);
}

TreeModel::~TreeModel()
{
    file->close();
    delete rootItem;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
{
    reader.setContentHandler(&handler);
    reader.parse(source);



}


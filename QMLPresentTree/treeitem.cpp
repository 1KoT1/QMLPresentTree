#include "treeitem.h"

TreeItem::TreeItem(QString content, QObject *parent) :
    QObject(parent),
    m_content(content),
    m_childItems(QList<TreeItem*>()),
    m_childItemsAsQObject(QList<QObject*>()),
    m_isOpen(false)
{
}

const QString &TreeItem::content() const{
    return m_content;
}

void TreeItem::setContent(const QString &content){
    if(content != m_content){
        m_content = content;
        emit contentChanged();
    }
}

const QList<TreeItem *> &TreeItem::childItems() const{
    return m_childItems;
}

const QList<QObject *> &TreeItem::childItemsAsQObject() const{
    return m_childItemsAsQObject;
}

void TreeItem::addChildItem(TreeItem *childItem){
    m_childItems.append(childItem);
    m_childItemsAsQObject.append(childItem);
    emit childItemsChanged();
    if(m_childItems.count() == 1)
        emit hasChildChanged();
}

bool TreeItem::isOpen() const{
    return m_isOpen;
}

void TreeItem::setIsOpen(bool isOpen){
    if(isOpen != m_isOpen){
        m_isOpen = isOpen;
        emit isOpenChanged();
    }
}

bool TreeItem::hasChild() const{
    return !m_childItems.isEmpty();
}

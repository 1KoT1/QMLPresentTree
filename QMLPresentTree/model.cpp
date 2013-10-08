#include "model.h"
#include "treeitem.h"

const int number = 100;

TreeItem *createTreeItem(){
    auto res = new TreeItem(QString::number(qrand() % number));
    while(qrand() % 2)
        res->addChildItem(createTreeItem());
    return res;
}

Model::Model(QObject *parent) :
    QObject(parent),
    m_tree(QList<TreeItem*>())
{
    m_tree.append(createTreeItem());
    m_tree.append(createTreeItem());
    m_tree.append(createTreeItem());
    m_tree.append(createTreeItem());
    m_tree.append(createTreeItem());
    m_tree.append(createTreeItem());
}

const QList<TreeItem *> &Model::tree() const{
    return m_tree;
}

const QList<QObject *> Model::treeAsQObjects() const{
    QList<QObject *> res;
    res.reserve(m_tree.count());
    for(auto i : m_tree)
        res.append(i);
    return res;
}

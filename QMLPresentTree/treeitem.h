#ifndef TREEITEM_H
#define TREEITEM_H

#include <QObject>

class TreeItem : public QObject
{
    Q_OBJECT
public:
    explicit TreeItem(QString content, QObject *parent = 0);

    Q_PROPERTY(QString content READ content NOTIFY contentChanged)
    const QString & content() const;
    void setContent(const QString & content);

    Q_PROPERTY(QList<QObject*> childItems READ childItemsAsQObject NOTIFY childItemsChanged)
    const QList<TreeItem *> &childItems() const;
    const QList<QObject *> &childItemsAsQObject() const;
    void addChildItem(TreeItem * childItem);

    Q_PROPERTY(bool isOpen READ isOpen WRITE setIsOpen NOTIFY isOpenChanged)
    bool isOpen() const;
    void setIsOpen(bool isOpen);

    Q_PROPERTY(bool hasChild READ hasChild NOTIFY hasChildChanged)
    bool hasChild() const;
signals:
    void contentChanged();
    void childItemsChanged();
    void isOpenChanged();
    void hasChildChanged();
public slots:
private:
    QString m_content;
    QList<TreeItem *> m_childItems;
    QList<QObject *> m_childItemsAsQObject;
    bool m_isOpen;
};

#endif // TREEITEM_H

#ifndef PANEL_H
#define PANEL_H

#include <QtGui>
#include "Data/Serialize.h"

namespace Fc{

}

class Panel : public QWidget{
    Q_OBJECT
public:
    explicit Panel(QWidget *parent = 0);
    void setConnected(QString, bool);

signals:
    void needAff(UFriend*, MediaType);
    
public slots:
    void appendFriend(UFriend*);
    void deleteFriend(UFriend*);

private slots:
    void collapse(QModelIndex);
    void expand(QModelIndex);
    void deleteFriend(QObject*);
    void click(QModelIndex);

private:
    void setInUser(QStandardItem*);
    QStandardItemModel *model;
    QTreeView tree;
    QList<UFriend*> friends;
};

#endif // PANEL_H

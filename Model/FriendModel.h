#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include <QStandardItemModel>
#include "Data/Serialize.h"

class FriendModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit FriendModel(QObject *parent = 0);
    void add(UFriend friends);
/*    UFriend get(int ID);
    bool remove(int ID);
    void update(UFriend friendUpdate);
    bool contains(int ID);
    QMap<unsigned int, unsigned int> getVersioning();
    void save(QString path);
    void load(QString path);

signals:
    void isUpdated();
*/
public slots:

};

#endif // FRIENDMODEL_H

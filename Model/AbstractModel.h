#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <QObject>
#include <QStandardItemModel>

class AbstractModel : public QObject{
    Q_OBJECT
public:
    explicit AbstractModel(QObject *parent = 0);
    virtual bool remove(unsigned int ID)=0;
    virtual bool contains(unsigned int ID)=0;
    virtual void save(QString path)=0;
    virtual void load(QString path)=0;
    virtual QMap<unsigned int, unsigned int> getVersioning()=0;
    QStandardItemModel* getModel();

signals:
    void isUpdated();

public slots:

private:
    QStandardItemModel *model;
};

#endif // ABSTRACTMODEL_H

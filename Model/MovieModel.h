#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include "AbstractModel.h"
#include <QFile>
#include "../Data/Serialize.h"

class MovieModel : public AbstractModel
{
    Q_OBJECT
public:
    explicit MovieModel(QObject *parent = 0);
    void add(UFilm film);
    UFilm get(unsigned int ID);
    void update(UFilm filmUpdate);
    virtual QMap<unsigned int, unsigned int> getVersioning();
    virtual bool remove(unsigned int ID);
    virtual bool contains(unsigned int ID);
    virtual void save(QString path);
    virtual void load(QString path);

signals:

public slots:

private:
    QMap<unsigned int, SFilm> sFilm;
    QMap<unsigned int, UFilm> uFilm;

};

#endif // MOVIEMODEL_H

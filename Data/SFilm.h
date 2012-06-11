#ifndef SFILM_H
#define SFILM_H
#include "AbstractMedia.h"
#include <QDate>

class SFilm : public AbstractMedia{

public:
    explicit SFilm();

    friend QDataStream& operator<<(QDataStream &out, const SFilm& lol);
    friend QDataStream& operator>>(QDataStream &in, SFilm& lol);

    virtual QByteArray toEssential() const;

    QString synopsis;
    QStringList acteurs, realisateur, genre;
    QDate parution;
    QTime time;
};

#endif // SFILM_H

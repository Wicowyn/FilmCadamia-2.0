#ifndef UFILM_H
#define UFILM_H
#include "SFilm.h"
#include "InfoPerso.h"

class UFilm : public SFilm, public InfoPerso{
public:
    explicit UFilm();

    friend QDataStream& operator<<(QDataStream &out, const UFilm& lol);
    friend QDataStream& operator>>(QDataStream &in, UFilm& lol);

signals:

public slots:


};

#endif // UFILM_H

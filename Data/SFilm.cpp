#include "SFilm.h"
#include "AbstractMedia.h"

SFilm::SFilm(){
    type=Film;
}

QByteArray SFilm::toEssential() const{
    QByteArray paquet;
    QDataStream data(&paquet, QIODevice::WriteOnly);

    data<<(SFilm&) *this;

    return paquet;
}

#include "Serialize.h"

void initSerialize(){
    qRegisterMetaTypeStreamOperators<MediaType>("MediaType");
    qMetaTypeId<MediaType>();
//    qRegisterMetaTypeStreamOperators<AbstractMedia>("AbstractMedia");
//    qMetaTypeId<AbstractMedia>();
    qRegisterMetaTypeStreamOperators<InfoPerso>("InfoPerso");
    qMetaTypeId<InfoPerso>();
    qRegisterMetaTypeStreamOperators<SFilm>("SFilm");
    qMetaTypeId<SFilm>();
    qRegisterMetaTypeStreamOperators<UFilm>("UFilm");
    qMetaTypeId<UFilm>();
    qRegisterMetaTypeStreamOperators<SFriend>("SFriend");
    qMetaTypeId<SFriend>();
}

QDataStream& operator<<(QDataStream &out, const MediaType& lol){
    out<<qint16(lol);

    return out;
}

QDataStream& operator>>(QDataStream &in, MediaType& lol){
    qint16 temp;
    in>>temp;
    lol=MediaType(temp);
    return in;
}

QDataStream& operator<<(QDataStream &out, const AbstractMedia& lol){
    out<<lol.ID;
    out<<lol.name;
    out<<lol.version;
    out<<lol.type;
    out<<lol.noteGlobal;
    out<<lol.image;

    return out;
}

QDataStream& operator>>(QDataStream &in, AbstractMedia& lol){
    in>>lol.ID;
    in>>lol.name;
    in>>lol.version;
    in>>lol.type;
    in>>lol.noteGlobal;
    in>>lol.image;

    return in;
}

QDataStream& operator<<(QDataStream &out, const InfoPerso& lol){
    out<<lol.ajout;
    out<<lol.com;
    out<<lol.note;
    out<<lol.path;

    return out;
}

QDataStream& operator>>(QDataStream &in, InfoPerso& lol){
    in>>lol.ajout;
    in>>lol.com;
    in>>lol.note;
    in>>lol.path;

    return in;
}

QDataStream& operator<<(QDataStream &out, const SFilm& lol){
    out<<(AbstractMedia&) lol;
    out<<lol.acteurs;
    out<<lol.realisateur;
    out<<lol.genre;
    out<<lol.parution;
    out<<lol.synopsis;
    out<<lol.time;

    return out;
}

QDataStream& operator>>(QDataStream &in, SFilm& lol){
    in>>(AbstractMedia&) lol;
    in>>lol.acteurs;
    in>>lol.realisateur;
    in>>lol.genre;
    in>>lol.parution;
    in>>lol.synopsis;
    in>>lol.time;

    return in;
}

QDataStream& operator<<(QDataStream &out, const UFilm& lol){
    out<<(SFilm&) lol;
    out<<(InfoPerso&) lol;

    return out;
}

QDataStream& operator>>(QDataStream& in, UFilm& lol){
    in>>(SFilm&) lol;
    in>>(InfoPerso&) lol;

    return in;
}

QDataStream& operator<<(QDataStream& out, const SFriend& lol){
    out<<(AbstractMedia&) lol;
    out<<lol.groupes;
    out<<lol.musiques;
    out<<lol.films;
    out<<lol.series;
    out<<lol.photos;

    return out;
}

QDataStream& operator>>(QDataStream& in, SFriend& lol){
    in>>(AbstractMedia&) lol;
    in>>lol.groupes;
    in>>lol.musiques;
    in>>lol.films;
    in>>lol.series;
    in>>lol.photos;

    return in;
}

QDataStream& operator<<(QDataStream& out, const UFriend& lol){
    out<<(SFriend&) lol;
    out<<(InfoPerso&) lol;

    return out;
}

QDataStream& operator>>(QDataStream& in, UFriend& lol){
    in>>(SFriend&) lol;
    in>>(InfoPerso&) lol;

    return in;
}

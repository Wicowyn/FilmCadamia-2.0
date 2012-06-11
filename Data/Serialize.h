#ifndef SERIALIZE_H
#define SERIALIZE_H

//Ne pas oublié l'amitié
#include <QDataStream>
#include <QVariant>
#include "../Command.h"
#include "AbstractMedia.h"
#include "InfoPerso.h"
#include "SFilm.h"
#include "UFilm.h"
#include "SFriend.h"
#include "UFriend.h"

void initSerialize();

Q_DECLARE_METATYPE(MediaType)
QDataStream& operator<<(QDataStream &out, const MediaType& lol);
QDataStream& operator>>(QDataStream &in, MediaType& lol);

//Q_DECLARE_METATYPE(AbstractMedia)
QDataStream& operator<<(QDataStream &out, const AbstractMedia& lol);
QDataStream& operator>>(QDataStream &in, AbstractMedia& lol);

Q_DECLARE_METATYPE(InfoPerso)
QDataStream& operator<<(QDataStream &out, const InfoPerso& lol);
QDataStream& operator>>(QDataStream &in, const InfoPerso& lol);

Q_DECLARE_METATYPE(SFilm)
QDataStream& operator<<(QDataStream &out, const SFilm& lol);
QDataStream& operator>>(QDataStream &in, SFilm& lol);

Q_DECLARE_METATYPE(UFilm)
QDataStream& operator<<(QDataStream &out, const UFilm& lol);
QDataStream& operator>>(QDataStream &in, UFilm& lol);

Q_DECLARE_METATYPE(SFriend)
QDataStream& operator<<(QDataStream &out, const SFriend& lol);
QDataStream& operator>>(QDataStream &out, SFriend& lol);

Q_DECLARE_METATYPE(UFriend)
QDataStream& operator<<(QDataStream &out, const UFriend& lol);
QDataStream& operator>>(QDataStream &out, UFriend& lol);



#endif // SERIALIZE_H

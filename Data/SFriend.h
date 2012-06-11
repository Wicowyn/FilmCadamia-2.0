#ifndef SFRIEND_H
#define SFRIEND_H
#include <QDataStream>
#include "AbstractMedia.h"

class SFriend : public AbstractMedia
{
public:
    SFriend();

    friend QDataStream& operator<<(QDataStream &out, const SFriend& lol);
    friend QDataStream& operator>>(QDataStream &in, SFriend& lol);

    virtual QByteArray toEssential() const;

    QStringList groupes;
    QList <unsigned int> musiques, films, series, photos;
};

#endif // SFRIEND_H

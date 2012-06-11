#ifndef UFRIEND_H
#define UFRIEND_H
#include "SFriend.h"
#include "InfoPerso.h"

class UFriend : public SFriend, public InfoPerso
{
public:
    UFriend();

    friend QDataStream& operator<<(QDataStream &out, const UFriend& lol);
    friend QDataStream& operator>>(QDataStream &in, UFriend& lol);
};

#endif // UFRIEND_H

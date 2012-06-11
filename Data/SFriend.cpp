#include "SFriend.h"

SFriend::SFriend(){

}

QByteArray SFriend::toEssential() const{
    QByteArray paquet;
    QDataStream data(&paquet, QIODevice::WriteOnly);

    data<<(SFriend&) *this;

    return paquet;
}

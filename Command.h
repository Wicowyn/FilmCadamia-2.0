#ifndef COMMAND_H
#define COMMAND_H
#include <QDataStream>

namespace Fcn{
    enum Commande{      //à gérer en qint16
        logIn=0, logInOn, logInOff,
        requestCreateAccount, notCreateAccount, yesCreateAccount,
        requestEtatFriends, etatFriends,
        requestNewGP, notNewGP, yesNewGP,
        requestJoinGP, notJoinGP, yesJoinGP,
        requestAllInfoFilmOf, allInfoFilmOf,
        updateLibrary, updateFriendLibrary, checkFriend
    };


}

class Package{ //à usage unique, comme les klenex ;)
public:
    Package();
    template <typename T>
    void operator <<(const T& lol) {data<<lol;}
    QByteArray toEnd();
    void setCom(Fcn::Commande);

private:
    QDataStream data;
    QByteArray paquet;
    Fcn::Commande com;
};

#endif // COMMAND_H

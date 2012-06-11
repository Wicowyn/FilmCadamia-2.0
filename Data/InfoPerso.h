#ifndef INFOPERSO_H
#define INFOPERSO_H
#include <QDate>

class InfoPerso{
public:
    InfoPerso();

    friend QDataStream& operator<<(QDataStream &out, const InfoPerso& lol);
    friend QDataStream& operator>>(QDataStream &in, const InfoPerso& lol);

    QString com, path;
    int note;
    QDate ajout;
};

#endif // INFOPERSO_H

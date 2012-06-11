#ifndef ABSTRACTMEDIA_H
#define ABSTRACTMEDIA_H

#include <QPixmap>

enum MediaType{
    Musique=0, Film, Serie, Photo, Radio
};

class AbstractMedia{
public:
    AbstractMedia();
//    AbstractMedia(const AbstractMedia &copie, QObject *parent=0);

    friend QDataStream& operator<<(QDataStream &out, const AbstractMedia& lol);
    friend QDataStream& operator>>(QDataStream &in, AbstractMedia& lol);

    virtual QByteArray toEssential() const=0;
    QByteArray getHeader();

signals:

public slots:

public:
    QString name;
    unsigned int ID, version, noteGlobal;
    MediaType type;
    QPixmap image;
};

#endif // ABSTRACTMEDIA_H

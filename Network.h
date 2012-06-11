#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QStandardItemModel>
#include "Data/Serialize.h"
#include "Command.h"
#include "Model/MovieModel.h"
#include <QFile>
#include <QTimer>

namespace Fc{
    enum Request{
        Nada=0, Connect, CreateAccount
    };
}

class Network : public QObject{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);
    ~Network();
    bool isOnline();
    void setModel(MovieModel *model);

public slots:
//    void actuLibrary();
    
signals:
    void connected(bool);
    void isConnected(UFriend*, bool);
    
private slots:
    void connected();
    void newData();      //moyen good
    void actuLibrary();  //good

private:
    //void updateFriendLibrary(QList<UFriend>);
    void updateFriendEtat(QMap<QString, bool>);
    QTcpSocket socket;
    bool online;
    Fc::Request lastRequest;
    QString login, password;
    QMultiMap<MediaType, int> buffActuLibrary;
    QTimer timerBuff;
    MovieModel *modelMovie;
};

#endif // NETWORK_H

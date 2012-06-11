#include "Network.h"
//kikoolol
Network::Network(QObject *parent): QObject(parent){

    online=false;
    lastRequest=Fc::Nada;
    QFile file("bddData.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream data(&file);
    data>>buffActuLibrary;

    connect(&socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(newData()));
    connect(&timerBuff, SIGNAL(timeout()), this, SLOT(actuLibrary()));
}

Network::~Network(){
    QFile file("bddData.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream data(&file);
    data<<buffActuLibrary;
}

bool Network::isOnline(){
    return online;
}

void Network::connected(){
    Package pack;
    switch(int(lastRequest)){
    case Fc::Connect:
        pack.setCom(Fcn::logIn);
        pack<<login;
        pack<<password;
        socket.write(pack.toEnd());
        break;

     case Fc::CreateAccount:

        break;
    }
}

void Network::newData(){
    static qint64 tailleMs=0;
    QDataStream in(&socket);
    if(tailleMs==0){
        if(socket.bytesAvailable()<int(sizeof(qint64))) return;
        in>>tailleMs;
    }
    if(socket.bytesAvailable()<tailleMs) return;

    QString msg;
    qint16 command;
    in>>command;
    qDebug()<<"Reception de donnée de type: "<<command;

    switch(command){
    case Fcn::logInOn:
        online=true;
        emit connected(online);
        actuLibrary();
//        tab->removeTab(0);
//        tab->addTab(treeView, "Groupes");
//        tab->addTab(createGP, "Créer");
//        tab->addTab(joinGP, "Rejoindre");
        break;
    case Fcn::logInOff:
        online=false;
        in>>msg;
//        if(msg=="bad login") home->setInfoLogin("Login incorrect");
//        else if(msg=="bad password") home->setInfoPassword("Mot de passe incorrect");
        emit connected(online);
        break;
    case Fcn::etatFriends:
        break;
    case Fcn::notNewGP:
//        createGP->setInfo("Echec, groupe déja existant");
        qDebug()<<"not new GP";
        break;
    case Fcn::notJoinGP:
        in>>msg;
//        joinGP->setInfo(msg);
        qDebug()<<"not join GP";
        break;
    case Fcn::notCreateAccount:
//        welcome->setInfoLogin("Login déja utiliser");
        break;
    case Fcn::yesNewGP:
//        createGP->setInfo("Réussi");
        qDebug()<<"yes new GP";
        break;
    case Fcn::yesJoinGP:
//        joinGP->setInfo("Réussi");
        qDebug()<<"yes join GP";
        break;
    case Fcn::yesCreateAccount:
//        welcome->successful();
        break;
    case Fcn::updateFriendLibrary:
        QList<UFriend> list;
        in>>list;
//        updateFriendLibrary(list);
        break;
    }
    tailleMs=0;
}

void Network::actuLibrary(){
    if(!isOnline() || buffActuLibrary.empty()) return;
    Package pack;
    pack.setCom(Fcn::updateLibrary);
    pack<<buffActuLibrary;
    socket.write(pack.toEnd());
    buffActuLibrary.clear();
    timerBuff.stop();
}

void Network::setModel(MovieModel *model){
    modelMovie=model;
}

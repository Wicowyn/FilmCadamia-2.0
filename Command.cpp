#include "Command.h"

Package::Package(): data(&paquet, QIODevice::WriteOnly){

}
/*
template <typename T>
void Package::operator <<(const T& lol){
    data<<lol;
}*/

QByteArray Package::toEnd(){
    QByteArray paquetF;
    QDataStream dataF(&paquetF, QIODevice::WriteOnly);
    dataF<<qint64(0);
    dataF<<qint16(com);
    dataF<<paquet;
    dataF.device()->seek(0);
    dataF<<qint64(paquetF.size()-sizeof(qint64));
    paquet.clear();
    return paquetF;
}

void Package::setCom(Fcn::Commande kikoo){
    com=kikoo;
}

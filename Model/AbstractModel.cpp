#include "AbstractModel.h"

AbstractModel::AbstractModel(QObject *parent) : QObject(parent){
    model=new QStandardItemModel(this);
}

QStandardItemModel* AbstractModel::getModel(){
    return model;
}

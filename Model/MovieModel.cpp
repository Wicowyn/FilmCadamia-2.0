#include "MovieModel.h"

MovieModel::MovieModel(QObject *parent) : AbstractModel(parent){
    model->setProperty("itemWidth", 160);
    model->setProperty("itemHeight", 213);

}

void MovieModel::add(UFilm film){

}

UFilm MovieModel::get(unsigned int ID){

}

bool MovieModel::remove(unsigned int ID){
    sFilm.remove(ID);
    uFilm.remove(ID);

}

void MovieModel::update(UFilm filmUpdate){

}

bool MovieModel::contains(unsigned int ID){

}

QMap<unsigned int, unsigned int> MovieModel::getVersioning(){

}

void MovieModel::save(QString path){

}

void MovieModel::load(QString path){

}


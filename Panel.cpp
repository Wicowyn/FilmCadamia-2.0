#include "Panel.h"

Panel::Panel(QWidget *parent) : QWidget(parent){
    model=new QStandardItemModel(this);
    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->addWidget(&tree);
    setLayout(layout);

    tree.setModel(model);
    tree.setEditTriggers(QAbstractItemView::NoEditTriggers);
    tree.setHeaderHidden(true);
    QStandardItem *bibli=new QStandardItem(tr("Bibliothéque"));
    setInUser(bibli);

    model->appendRow(bibli);
    model->appendRow(new QStandardItem(tr("Réseau")));
    tree.expandAll();

    connect(&tree, SIGNAL(collapsed(QModelIndex)), this, SLOT(collapse(QModelIndex)));
    connect(&tree, SIGNAL(expanded(QModelIndex)), this, SLOT(expand(QModelIndex)));
    connect(&tree, SIGNAL(clicked(QModelIndex)), this, SLOT(click(QModelIndex)));
}

void Panel::setInUser(QStandardItem *item){
    QVector<QStandardItem*> tab;
    tab.append(new QStandardItem(QIcon("musique.png"), tr("Musique")));
    tab[0]->setData(Musique);
    tab.append(new QStandardItem(QIcon("film.png"), tr("Film")));
    tab[1]->setData(Film);
    tab.append(new QStandardItem(QIcon("serie.png"),tr("Série")));
    tab[2]->setData(Serie);
    tab.append(new QStandardItem(QIcon("photos.png"), tr("Image")));
    tab[3]->setData(Photo);
    tab.append(new QStandardItem(QIcon("radio.png"), tr("Radio")));
    tab[4]->setData(Radio);
    for(int i=0; i<tab.count(); i++) item->appendRow(tab[i]);
}

void Panel::appendFriend(UFriend *fr){
    QStandardItem *network=model->item(1);
    deleteFriend(fr); //histoire d'éviter les doublons..

    QStringList groupes=fr->groupes;
    for(int i=0; i<groupes.count(); i++){
        int a=0;
        while(a<network->rowCount()){
            if(network->child(a)->text()==groupes.at(i)){
                QStandardItem *user=new QStandardItem(QIcon("deco.png"), fr->name);
                setInUser(user);
                user->setData(QVariant::fromValue<void*>(fr));
                network->child(a)->appendRow(user);
                break;
            }
            a++;
        }
        if(a==network->rowCount()){
            QStandardItem *gp=new QStandardItem(groupes.at(i));
            gp->setData("GP");
            QStandardItem *user=new QStandardItem(QIcon("deco.png"), fr->name);
            setInUser(user);
            user->setData(QVariant::fromValue<void*>(fr));
            gp->appendRow(user);
            network->appendRow(gp);
        }
    }
    //connect(fr, SIGNAL(destroyed(QObject*)), this, SLOT(deleteFriend(QObject*)));
}

void Panel::setConnected(QString str, bool val){
    QStandardItem *network=model->item(1);
    for(int i=0; i<network->rowCount(); i++){
        QStandardItem *gp=network->child(i);
        for(int a=0; a<gp->rowCount(); a++){
            if(gp->child(a)->text()==str) gp->child(a)->setIcon(QIcon(val ? "co.png" : "deco.png"));
        }
    }
}

void Panel::deleteFriend(UFriend *fr){
    QStandardItem *network=model->item(1);
    for(int i=0; i<network->rowCount(); i++){
        QStandardItem *gp=network->child(i);
        for(int a=0; a<gp->rowCount(); a++){
            if(gp->child(a)->text()==fr->name){
                model->removeRow(a, gp->index());
                a--;
            }
        }
        if(gp->rowCount()==0){
            model->removeRow(i, network->index());
            i--;
        }
    }
}

void Panel::deleteFriend(QObject *ob){
    //UFriend *kikoo=static_cast<UFriend*> (ob);
    //deleteFriend(kikoo);
}

void Panel::collapse(QModelIndex index){
    QStandardItem *child=model->itemFromIndex(index);
    if(child->data().toString()=="GP") for(int i=0; i<child->rowCount(); i++) tree.collapse(child->child(i)->index());
}

void Panel::expand(QModelIndex index){
    QStandardItem *pr=model->itemFromIndex(index)->parent();
    if(!pr) return;
    if(pr->data().toString()=="GP") for(int i=0; i<pr->rowCount(); i++) if(pr->child(i)!=model->itemFromIndex(index)) tree.collapse(pr->child(i)->index());

}

void Panel::click(QModelIndex index){
    QString str=model->itemFromIndex(index)->data().toString();
    if(model->itemFromIndex(index)->data().type()==QVariant::Int) emit needAff(static_cast<UFriend*> (model->itemFromIndex(index)->parent()->data().value<void*>()), MediaType(model->itemFromIndex(index)->data().toInt()));
}

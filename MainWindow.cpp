#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    panel=new Panel;

    MovieModel *model=new MovieModel(this);
    MovieList *movies=new MovieList(this);
    movies->setModel(model->getModel());
    Network *net=new Network();
    net->setModel(model);

    setCentralWidget(movies);
    /*movies->addMovie("coco.jpg");
    movies->addMovie("time out.jpg");

    QString str="Kikoo";
    QString str2="trou";
    Friend *kikoo=new Friend;
    Friend *trou=new Friend;
    kikoo->setName(str);
    trou->setName(str2);
    QStringList list;
    list.append("lol");
    trou->setGroupes(list);
    list.append("kikoo");
    kikoo->setGroupes(list);
    panel->appendFriend(kikoo);
    panel->appendFriend(trou);
    panel->setConnected("Kikoo", true);
    panel->appendFriend(kikoo);
    Film p;
    QVariant variant=QVariant::fromValue(p);*/
    //delete kikoo;

//    QVariant var(Film());
//    connect(panel, SIGNAL(needAff(Friend*,Fc::MediaType)), this, SLOT(kikoo(Friend*,Fc::MediaType)));

    UFilm pop;
//    pop.ID=6;
//    pop.synopsis="tip";
//    pop.note=10;

    QFile file("tiptop");
    file.open(QIODevice::ReadOnly);
    QDataStream data(&file);
    data>>pop;
    file.close();

    qDebug()<<pop.ID<<pop.synopsis<<pop.note;
}

MainWindow::~MainWindow(){

}

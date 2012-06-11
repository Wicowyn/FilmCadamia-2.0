#include "MovieList.h"

MovieList::MovieList(QWidget *parent) : QListView(parent){
    setItemDelegate(new MovieDelegate());

    setFlow(QListView::LeftToRight);
    setWrapping(true);
    setResizeMode(QListView::Adjust);
    setMouseTracking(true);
    setUniformItemSizes(true);
    setSpacing(10);

   // setModel();

}

void MovieList::addMovie(QString img){
    QStandardItem *item=new QStandardItem(img);
    //item->setData(img, Qt::DisplayRole);
    model->appendRow(item);
}

void MovieList::mouseReleaseEvent(QMouseEvent *event){
    QListView::mousePressEvent(event);
    QModelIndex index = indexAt(event->pos());
    if (!index.isValid()) clearSelection();
    qDebug()<<modelColumn();
}

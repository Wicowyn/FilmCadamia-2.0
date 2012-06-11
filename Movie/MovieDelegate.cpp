#include "MovieDelegate.h"

MovieDelegate::MovieDelegate(QObject *parent) : QStyledItemDelegate(parent){

}

void MovieDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    painter->save();
    QRect rect=option.rect;
    rect.translate(5, 5);
    rect.setWidth(index.model()->property("itemWidth").toInt());
    rect.setHeight(index.model()->property("itemHeight").toInt());

    QImage img(index.data().toString());
    QRect rectBorder=rect;
    QPen penBorder;

    penBorder.setJoinStyle(Qt::RoundJoin);
    penBorder.setCapStyle(Qt::RoundCap);

    painter->fillRect(rectBorder, Qt::black);

//    qDebug()<<QString::number(uint(option.state), 16);

    if((option.state & QStyle::State_MouseOver) && !(option.state & QStyle::State_Selected)){
//        qDebug()<<"MouseOver";
        penBorder.setWidth(5);
        penBorder.setColor(Qt::black);
        painter->setPen(penBorder);

        painter->setOpacity(0.5);
        painter->drawImage(rect, img);
        painter->setOpacity(1);
        painter->drawRoundRect(rectBorder, 5, 5);
    }else
        if(option.state & QStyle::State_Selected){
//            qDebug()<<"Selected";
            penBorder.setWidth(7);
            penBorder.setColor(Qt::blue);
            painter->setPen(penBorder);

            painter->drawImage(rect, img);
            painter->drawRoundRect(rectBorder, 5, 5);
        }
        else{
//            qDebug()<<"autre";
            painter->drawImage(rect, img);
            penBorder.setWidth(5);
            penBorder.setColor(Qt::black);
            painter->setPen(penBorder);
            painter->drawRoundRect(rectBorder, 5, 5);
        }

    painter->restore();
}

QSize MovieDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const{
    return QSize(index.model()->property("itemWidth").toInt()+10, index.model()->property("itemHeight").toInt()+10);
}

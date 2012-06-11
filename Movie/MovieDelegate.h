#ifndef MOVIEDELEGATE_H
#define MOVIEDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QDebug>

class MovieDelegate : public QStyledItemDelegate{
    Q_OBJECT
public:
    explicit MovieDelegate(QObject *parent = 0);


protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint (const QStyleOptionViewItem &option, const QModelIndex &index) const;


signals:

public slots:

};

#endif // MOVIEDELEGATE_H

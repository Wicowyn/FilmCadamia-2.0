#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <QListView>
#include <QtGui>
#include "MovieDelegate.h"
#include "Data/Serialize.h"
#include "Model/MovieModel.h"

class MovieList : public QListView
{
    Q_OBJECT
public:
    explicit MovieList(QWidget *parent = 0);
    void addMovie(QString img);

protected:
    virtual void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:

private :
    QStandardItemModel *model;

};

#endif // MOVIELIST_H

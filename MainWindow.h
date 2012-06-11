#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "Panel.h"
//#include "Data/Serialize.h"
#include "Movie/MovieList.h"
#include "Network.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private:
    Panel *panel;

};

#endif // MAINWINDOW_H

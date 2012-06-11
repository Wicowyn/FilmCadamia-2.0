#include <QtGui/QApplication>
#include "MainWindow.h"
#include "Data/Serialize.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    initSerialize();
    MainWindow w;
    w.show();
    
    return a.exec();
}

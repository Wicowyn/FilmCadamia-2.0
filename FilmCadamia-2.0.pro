#-------------------------------------------------
#
# Project created by QtCreator 2012-02-12T21:09:48
#
#-------------------------------------------------

QT       += core gui
QT       += network

TARGET = FilmCadamia_2
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Panel.cpp \
    Network.cpp \
    Command.cpp \
    Movie/MovieList.cpp \
    Movie/MovieDelegate.cpp \
    Data/Serialize.cpp \
    Model/MovieModel.cpp \
    Model/FriendModel.cpp \
    Data/AbstractMedia.cpp \
    Data/SFilm.cpp \
    Data/InfoPerso.cpp \
    Data/UFilm.cpp \
    Data/SFriend.cpp \
    Data/UFriend.cpp \
    Model/AbstractModel.cpp

HEADERS  += MainWindow.h \
    Panel.h \
    Network.h \
    Command.h \
    Movie/MovieList.h \
    Movie/MovieDelegate.h \
    Data/Serialize.h \
    Model/MovieModel.h \
    Model/FriendModel.h \
    Data/AbstractMedia.h \
    Data/SFilm.h \
    Data/InfoPerso.h \
    Data/UFilm.h \
    Data/SFriend.h \
    Data/UFriend.h \
    Model/AbstractModel.h

#-------------------------------------------------
#
# Project created by QtCreator 2019-12-21T16:02:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shooting_plane
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Enemy/enemy_plane.cpp \
    Mine/myplane.cpp

HEADERS  += mainwindow.h \
    Enemy/enemy_plane.h \
    Mine/myplane.h

FORMS    += mainwindow.ui \
    Enemy/enemy_plane.ui \
    Mine/myplane.ui

RESOURCES += \
    resource.qrc

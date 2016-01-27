#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T09:48:42
#
#-------------------------------------------------

QT       += core gui
QT       += network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp

HEADERS  += server.h \
    boatserver.h

FORMS    += server.ui

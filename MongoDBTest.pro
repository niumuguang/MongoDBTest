#-------------------------------------------------
#
# Project created by QtCreator 2014-06-20T13:38:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MongoDBTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp


INCLUDEPATH += $$PWD/Include/mongo
DEPENDPATH += $$PWD/Include/mongo

PRE_TARGETDEPS += $$PWD/Library/libmongoclient.a


LIBS += -L$$PWD/Library/BoostLib/ -lboost_system

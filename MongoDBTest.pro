#-------------------------------------------------
#
# Project created by QtCreator 2014-06-20T13:38:44
#
#-------------------------------------------------

QT       += core
QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QT       -= gui

TARGET = MongoDBTest
#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    CTP/md/mdspi.cpp

HEADERS += mainwindow.h \
    config.h \
    CTP/md/mdspi.h \
    CTP/api/trade/linux64/public/ThostFtdcMdApi.h \
    CTP/api/trade/linux64/public/ThostFtdcTraderApi.h \
    CTP/api/trade/linux64/public/ThostFtdcUserApiDataType.h \
    CTP/api/trade/linux64/public/ThostFtdcUserApiStruct.h

FORMS   += mainwindow.ui

INCLUDEPATH += $$PWD/Include/mongo
DEPENDPATH += $$PWD/Include/mongo

PRE_TARGETDEPS += $$PWD/Library/libmongoclient.a


LIBS += -L$$PWD/Library/BoostLib/ -lboost_system

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h

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
    CTP/md/mdspi.cpp \
    cmysql_api.cpp \
    chstimer.cpp

HEADERS += mainwindow.h \
    config.h \
    CTP/md/mdspi.h \
    CTP/api/trade/win/public/ThostFtdcMdApi.h \
    CTP/api/trade/win/public/ThostFtdcTraderApi.h \
    CTP/api/trade/win/public/ThostFtdcUserApiDataType.h \
    CTP/api/trade/win/public/ThostFtdcUserApiStruct.h \
    cmysql_api.h \
    CShareFun.h \
    chstimer.h

FORMS   += mainwindow.ui

INCLUDEPATH += $$PWD/Include/mongo
DEPENDPATH += $$PWD/Include/mongo

PRE_TARGETDEPS += $$PWD/Library/libmongoclient.a


LIBS += -L$$PWD/Library/BoostLib/ -lboost_system



FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/CTP/api/trade/linux64/lib/release/ -lthostmduserapi
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/CTP/api/trade/linux64/lib/debug/ -lthostmduserapi
#else:unix:!macx: LIBS += -L$$PWD/CTP/api/trade/linux64/lib/ -lthostmduserapi

#INCLUDEPATH += $$PWD/CTP/api/trade/linux64
#DEPENDPATH += $$PWD/CTP/api/trade/linux64


#INCLUDEPATH += $$PWD/api/risk

win32 {
    INCLUDEPATH += $$PWD/CTP/api/trade/win
    LIBS += -L$$PWD/CTP/api/risk/lib/ -lriskuserapi -L$$PWD/CTP/api/trade/win/lib/ -lthostmduserapi -lthosttraderapi
} unix {
    INCLUDEPATH += $$PWD/CTP/api/trade/linux64
#    LIBS += -L$$PWD/api/risk/lib/ -lriskuserapi
    LIBS += -L$$PWD/CTP/api/trade/linux64/lib/ -lthostmduserapi -lthosttraderapi
    QMAKE_LFLAGS += -pthread
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lmysqlcppconn
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lmysqlcppconn
else:unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/release/libmysqlcppconn.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/debug/libmysqlcppconn.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/release/mysqlcppconn.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/debug/mysqlcppconn.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/lib/libmysqlcppconn.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/release/ -lmysqlclient
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/debug/ -lmysqlclient
else:unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lmysqlclient

INCLUDEPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/x86_64-linux-gnu/release/libmysqlclient.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/x86_64-linux-gnu/debug/libmysqlclient.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/x86_64-linux-gnu/release/mysqlclient.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/x86_64-linux-gnu/debug/mysqlclient.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/lib/x86_64-linux-gnu/libmysqlclient.a

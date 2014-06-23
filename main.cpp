#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include <string.h>
#include <boost/timer.hpp>
#include <mongo/client/dbclient.h>
#include <mongo/client/connpool.h>

#include "mainwindow.h"

using namespace boost;
using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // test pull

    //cerr << "Start MySQL test" << endl;
    return a.exec();
}

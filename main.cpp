#include <QCoreApplication>
#include <iostream>
#include <string.h>
#include <boost/timer.hpp>
#include <mongo/client/dbclient.h>
#include <mongo/client/connpool.h>

using namespace boost;
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // test pull

    cerr << "Start MySQL test" << endl;
    return a.exec();
}

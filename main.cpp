#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include <string.h>
#include <boost/timer.hpp>
#include <mongo/client/dbclient.h>
#include <mongo/client/connpool.h>
#include "CTP/md/mdspi.h"

#include "mainwindow.h"
/**************************************************************
 *
 * ************************************************************/
#ifndef TEST_H_
#define TEST_H_

#include "config.h"

using namespace boost;
using namespace std;

//*******************************************************************//
CThostFtdcMdApi* pUserApi;
char FRONT_ADDR[] = "tcp://asp-sim2-md1.financial-trading-platform.com:26213";
TThostFtdcBrokerIDType BROKER_ID = "2030";
TThostFtdcInvestorIDType INVESTOR_ID = "00092";
TThostFtdcPasswordType PASSWORD = "888888";
char *ppInstrumentID[] = {"ag1412"};
int iInstrumentID = 1;
int iRequestID = 0;

//*******************************************************************//

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //cerr << "Start MySQL test" << endl;
    return a.exec();
}

#endif

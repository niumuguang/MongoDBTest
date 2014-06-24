#include "CTP/md/mdspi.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <cmysql_api.h>
#include "windows.h"
#include "win_event.h"

using namespace std;
#pragma warning(disable : 4996)

extern int requestId;  
extern HANDLE g_hEvent;

extern CThostFtdcMdApi* pUserApi;
extern char FRONT_ADDR[];
extern TThostFtdcBrokerIDType BROKER_ID;
extern TThostFtdcInvestorIDType INVESTOR_ID;
extern TThostFtdcPasswordType PASSWORD;
extern char* ppInstrumentID[];
extern int iInstrumentID;

extern int iRequestID;


//void CtpMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo,
//		int nRequestID, bool bIsLast)
//{
//  IsErrorRspInfo(pRspInfo);
//}

//void CtpMdSpi::OnFrontDisconnected(int nReason)
//{
//  cerr<<" ��Ӧ | �����ж�..."
//    << " reason=" << nReason << endl;
//}
		
//void CtpMdSpi::OnHeartBeatWarning(int nTimeLapse)
//{
//  cerr<<" ��Ӧ | ������ʱ����..."
//    << " TimerLapse = " << nTimeLapse << endl;
//}

//void CtpMdSpi::OnFrontConnected()
//{
//	cerr<<" ���ӽ���ǰ��...�ɹ�"<<endl;
//  SetEvent(g_hEvent);
//}

//void CtpMdSpi::ReqUserLogin(TThostFtdcBrokerIDType	appId,
//	        TThostFtdcUserIDType	userId,	TThostFtdcPasswordType	passwd)
//{
//	CThostFtdcReqUserLoginField req;
//	memset(&req, 0, sizeof(req));
//	strcpy(req.BrokerID, appId);
//	strcpy(req.UserID, userId);
//	strcpy(req.Password, passwd);
//	int ret = pUserApi->ReqUserLogin(&req, ++requestId);
//  cerr<<" ���� | ���͵�¼..."<<((ret == 0) ? "�ɹ�" :"ʧ��") << endl;
//  SetEvent(g_hEvent);
//}

//void CtpMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
//		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
//{
//	if (!IsErrorRspInfo(pRspInfo) && pRspUserLogin)
//	{
//    cerr<<" ��Ӧ | ��¼�ɹ�...��ǰ������:"
//      <<pRspUserLogin->TradingDay<<endl;
//	}
//  if(bIsLast) SetEvent(g_hEvent);
//}

//void CtpMdSpi::SubscribeMarketData(char* instIdList)
//{
//  vector<char*> list;
//  char *token = strtok(instIdList, ",");
//  while( token != NULL ){
//    list.push_back(token);
//    token = strtok(NULL, ",");
//  }
//  unsigned int len = list.size();
//  char** pInstId = new char* [len];
//  for(unsigned int i=0; i<len;i++)  pInstId[i]=list[i];
//	int ret=pUserApi->SubscribeMarketData(pInstId, len);
//  cerr<<" ���� | �������鶩��... "<<((ret == 0) ? "�ɹ�" : "ʧ��")<< endl;
//  SetEvent(g_hEvent);
//}

//void CtpMdSpi::OnRspSubMarketData(
//         CThostFtdcSpecificInstrumentField *pSpecificInstrument,
//         CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
//{
//	cerr<<" ��Ӧ |  ���鶩��...�ɹ�"<<endl;
//  if(bIsLast)  SetEvent(g_hEvent);
//}

//void CtpMdSpi::OnRspUnSubMarketData(
//             CThostFtdcSpecificInstrumentField *pSpecificInstrument,
//             CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
//{
//	cerr<<" ��Ӧ |  ����ȡ������...�ɹ�"<<endl;
//  if(bIsLast)  SetEvent(g_hEvent);
//}

//void CtpMdSpi::OnRtnDepthMarketData(
//             CThostFtdcDepthMarketDataField *pDepthMarketData)
//{
//  cerr<<" ���� | ��Լ:"<<pDepthMarketData->InstrumentID
//    <<" �ּ�:"<<pDepthMarketData->LastPrice
//    <<" ��߼�:" << pDepthMarketData->HighestPrice
//    <<" ��ͼ�:" << pDepthMarketData->LowestPrice
//    <<" ��һ��:" << pDepthMarketData->AskPrice1
//    <<" ��һ��:" << pDepthMarketData->AskVolume1
//    <<" ��һ��:" << pDepthMarketData->BidPrice1
//    <<" ��һ��:" << pDepthMarketData->BidVolume1
//    <<" �ֲ���:"<< pDepthMarketData->OpenInterest <<endl;
//}

//bool CtpMdSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
//{
//  bool ret = ((pRspInfo) && (pRspInfo->ErrorID != 0));
//  if (ret){
//    cerr<<" ��Ӧ | "<<pRspInfo->ErrorMsg<<endl;
//  }
//  return ret;
//}


void CtpMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cerr << "--->>>" << "OnRspError" << endl;
    IsErrorRspInfo(pRspInfo);
}

void CtpMdSpi::OnFrontDisconnected(int nReason)
{
    cerr << "--->>>" << "OnFrontDisconnected" << endl;
    cerr << "--->>> Reason = " << nReason << endl;
}

void CtpMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
    cerr << "--->>>" << "OnFrontConnected" << endl;
    ReqUserLogin();
}

void CtpMdSpi::OnFrontConnected()
{
    cerr << "--->>>" << "OnFrontConnected" << endl;
    m_sql = new CMySQL_Api("localhost",3306,"root", "niumuguang", "FutureDB","ag1409");
    ReqUserLogin();
}

void CtpMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cerr << "--->>> " << "OnRspUserLogin" << endl;

    if(bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        cerr << "--->>> get trade date = " << pUserApi->GetTradingDay() << endl;
        SubscribeMarketData();
    }
}

void CtpMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cerr << "OnRspSubMarketData" << endl;
}

void CtpMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cerr << "OnRspUnSubMarketData" << endl;
}

void CtpMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
    m_sql->WriteDB(pDepthMarketData);
    cerr << "-------------------------------------------------------------------" << endl;
    cerr << "AskPrice1:" << pDepthMarketData->AskPrice1 << endl;
    cerr << "BidPrice1:" << pDepthMarketData->BidPrice1 << endl;
    cerr << "AskVolume1:" << pDepthMarketData->AskVolume1 << endl;
    cerr << "BidVolume1:" << pDepthMarketData->BidVolume1 << endl;
    cerr << "AveragePrice:" << pDepthMarketData->AveragePrice << endl;
    cerr << "ClosePrice:" << pDepthMarketData->ClosePrice << endl;
    cerr << "CurrDelta:" << pDepthMarketData->CurrDelta << endl;
    cerr << "ExchangeID:" << pDepthMarketData->ExchangeID << endl;
    cerr << "ExchangeInstID:" << pDepthMarketData->ExchangeInstID << endl;
    cerr << "HighestPrice:" << pDepthMarketData->HighestPrice << endl;
    cerr << "InstrumentID:" << pDepthMarketData->InstrumentID << endl;
    cerr << "LastPrice:" << pDepthMarketData->LastPrice << endl;
    cerr << "LowerLimitPrice:" << pDepthMarketData->LowerLimitPrice << endl;
    cerr << "LowestPrice:" << pDepthMarketData->LowestPrice << endl;
    cerr << "OpenInterest:" << pDepthMarketData->OpenInterest << endl;
    cerr << "OpenPrice:" << pDepthMarketData->OpenPrice << endl;
    cerr << "PreClosePrice:" << pDepthMarketData->PreClosePrice << endl;
    cerr << "PreDelta:" << pDepthMarketData->PreDelta << endl;
    cerr << "PreOpenInterest:" << pDepthMarketData->PreOpenInterest << endl;
    cerr << "PreSettlementPrice:" << pDepthMarketData->PreSettlementPrice << endl;
    cerr << "TradingDay:" << pDepthMarketData->TradingDay << endl;
    cerr << "Turnover:" << pDepthMarketData->Turnover << endl;
    cerr << "UpdateMillisec:" << pDepthMarketData->UpdateMillisec << endl;
    cerr << "UpdateTime:" << pDepthMarketData->UpdateTime << endl;
    cerr << "UpperLimitPrice:" << pDepthMarketData->UpperLimitPrice << endl;
    cerr << "Volume:" << pDepthMarketData->Volume << endl;
}

void CtpMdSpi::ReqUserLogin()
{
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.UserID, INVESTOR_ID);
    strcpy(req.Password, PASSWORD);
    int iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
    cerr << "--->>> send user login request:" << ((iResult == 0) ? "Successull" : "Failed") << endl;

}

void CtpMdSpi::SubscribeMarketData()
{
    int iResult = pUserApi->SubscribeMarketData(ppInstrumentID, iInstrumentID);
    cerr << "--->>> send Subscribe Market request:" << ((iResult == 0)?"Successfull":"Failed")<<endl;
}

bool CtpMdSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    if(bResult)
    {
        cerr << "--->>> ErrorID = " << pRspInfo->ErrorID << ",MSG: " << pRspInfo->ErrorMsg <<endl;
    }
    return false;
}

#ifndef CSHAREFUN_H
#define CSHAREFUN_H
#endif // CSHAREFUN_H

#pragma once
#include <vector>
//#include "MinuteData.h"
#include <QString>
#include <QStringList>

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

//#define HOST "192.168.74.147"
#define HOST "localhost"
//#define USER "lio"
//#define DatabaseUSER "lio"
#define USER "root"
#define PORT "3306"
//#define PASSWD "root"
#define PASSWD "niumuguang"
#define DBNAME "FutureDB"
#define CHARSET "utf8"
//#define STANDARDIP "116.236.239.129"

//struct ListData
//{
//    char ID[10];
//    char TotalPacket[10];
//    bool Falg;
//    char Protocol[20];
//    char sIP[16],sMac[19],sPort[10];
//    char dIP[16],dMac[19],dPort[10];
//    char Len[10];
//    char Text[50];
//};

namespace xxx {

////////////////////////////////////////////////////////
/// \brief The HSTimer struct
/// HSTimer管理交易时间，判断时间是否在交易时间内
struct HSTimer
{
public:
    //    HSTimer(){
    //         m_Year = 0;
    //         m_Month = 0;
    //         m_Day = 0;
    //         m_Hour = 0;
    //         m_Minute = 0;
    //         m_Second = 0;
    //         m_MilliSecond = 0;

    //         m_StringTimer = _T("");
    //         m_StringDate = _T("");
    //    };

    //    HSTimer(QString TimeStr){
    //        m_StringTimer = TimeStr;
    //        SplitTimeStr();
    //    };
    HSTimer()
    {

    }

    HSTimer( QString DataStr, QString TimeStr, int MilliSecStr )
    {
        m_StringTimer = TimeStr;
        m_StringDate = DataStr;
        m_MilliSecond = MilliSecStr;

        SplitTimeStr();
        SplitDateStr();
//        std::cerr << m_StringTimer.toStdString() << std::endl;
//        std::cerr << m_StringDate.toStdString() << std::endl;
//        std::cerr << m_MilliSecond << std::endl;
    }

    HSTimer(QString TimeStr,QString DateStr){
//        m_StringTimer = TimeStr;
//        m_StringDate = DateStr;
//        SplitTimeStr();
//        SplitDateStr();
    }

    ~HSTimer(void){
    }

// 	friend int operator-(HSTimer com1,HSTimer com2)//友元运算符重载函数
// 	{
// 		return 0;
// 	};

// 	HSTimer& operator = (HSTimer TimeStr)//友元运算符重载函数
// 	{
// 		this = &TimeStr;
// 		//SplitTimeStr();
// 		return;
// 	};

    bool isSameMinute(const HSTimer &t1){
        if (t1.m_Year == m_Year && t1.m_Month == m_Month && t1.m_Day == m_Day && t1.m_Hour == m_Hour && t1.m_Minute == m_Minute)
        {
            return true;
        }
        return false;
    };


    bool isFifteenMinute(const HSTimer &t1)
    {
        if (t1.m_Year == m_Year && t1.m_Month == m_Month && t1.m_Day == m_Day)
        {
            if (m_Hour == t1.m_Hour)// 小时相同
            {
                if( int(m_Minute/15) == int(t1.m_Minute/15) )
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    bool isFiveMinute(const HSTimer &t1){
        if (t1.m_Year == m_Year && t1.m_Month == m_Month && t1.m_Day == m_Day)
        {
            if (m_Hour == t1.m_Hour)// 小时相同
            {
                if( int(m_Minute/5) == int(t1.m_Minute/5) )
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }


    bool operator==(const HSTimer &t1)const{
        if (t1.m_Year == m_Year && t1.m_Month == m_Month && t1.m_Day == m_Day && t1.m_Hour == m_Hour && t1.m_Minute == m_Minute && t1.m_Second == m_Second && t1.m_MilliSecond == m_MilliSecond)
        {
            return true;
        }
        return false;
    };

    bool isInTradeTime(){
        if (m_Hour == 0 && m_Minute == 0 && m_Second == 0 && m_MilliSecond == 0)
        {
            return false;
        }
        if (m_Hour == 8)
        {
            if(m_Minute == 59)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // 9:00 to 11:30
        else if(9 <= m_Hour && m_Hour < 12)
        {
            if (m_Hour== 11)
            {
                if (m_Minute > 30)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if (m_Hour == 10)
            {
                if (0 <= m_Minute && m_Minute < 16)
                {
                    return true;
                }
                else if( 15<m_Minute && m_Minute<29)
                {
                    return false;
                }
                else// 大于等于30分的
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
        }
        // 13:30 to 15:00
        else if ( 13 <= m_Hour && m_Hour <= 15)
        {
            if (m_Hour == 13)
            {
                // 25分以后为true
                if (0<=m_Minute && m_Minute<29)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if (m_Hour == 15)
            {
                if (m_Minute > 0)
                {
                    return false;
                }
                else if(m_Minute == 0)
                {
                    if (m_Second == 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            //////////////////////////////////////////////////////////////////////////
            // 14:00 返回 在时间范围
            else
            {
                return true;
            }
        }

        else if(m_Hour == 20)
        {
            if (m_Minute == 59)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // 21:00 to 23:59
        else if(21 <= m_Hour && m_Hour < 24)
        {
            return true;
        }
        // 00:00 to 02:30
        else if (0 <= m_Hour && m_Hour < 3)
        {
            if (m_Hour == 2)
            {
                if ( m_Minute > 30 )
                {
                    return false;
                }
                else
                {
                    if (m_Minute == 30)
                    {
                        if (m_Second == 0)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    return true;
                }
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    };

    bool isInOneMinute(HSTimer inputData)
    {
        if (m_Year == inputData.m_Year && m_Month == inputData.m_Month && m_Day == inputData.m_Day && m_Hour == inputData.m_Hour)
        {
            if (m_Minute == inputData.m_Minute)
            {
                return true;
            }
            else if( abs(m_Minute - inputData.m_Minute) == 59)
            {
                return false;
            }
 //
        }
        else
        {
            return false;
        }

    };

//    void SetData(QString TimeStr,QString DateStr){
//        m_StringTimer = TimeStr;
//        m_StringDate = DateStr;
//        SplitTimeStr();
//        SplitDateStr();
//    };


public:
    int m_Year;
    int m_Month;
    int m_Day;
    int m_Hour;
    int m_Minute;
    int m_Second;
    int m_MilliSecond;

    QString m_StringTimer;
    QString m_StringDate;

private:
    void SplitTimeStr(){
        int StringLen = m_StringTimer.length();
//        if (StringLen < 9)
//        {
//            for (int i=0; i<9-StringLen;i++)
//            {
//                m_StringTimer.Insert(0,_T("0"));
//            }
//        }

        //
        QString temp_Hour = m_StringTimer.mid(0,2);
        m_Hour= temp_Hour.toInt();
        QString temp_Minute = m_StringTimer.mid(3,2);
        m_Minute = temp_Minute.toInt();
        QString temp_Second = m_StringTimer.mid(6,2);
        m_Second = temp_Second.toInt();

    };

    void SplitDateStr(){
        vector<QString> res;

        QString strArr = m_StringDate;
        QString strSplit = "-";
        QStringList* arr = new QStringList;
        int iStart = 0 , iFind = 0;
        do
        {

            iFind = strArr.indexOf(strSplit,iStart);
            if(iFind == -1)
                arr->append(strArr.mid(iStart));
                //arr->Add(strArr.Mid(iStart));
            else
                arr->append(strArr.mid(iStart , iFind - iStart));
            iStart = iFind + 1;
        }while(iFind != -1);

        //arr->GetCount()
        for (int i=0; i<arr->length();i++)
        {
            res.push_back(arr->at(i));
        }
        // 用- 分割

        QString tempStr = res.at(0);
        //QString temp_Year = m_StringDate.Mid(0,4);
        m_Year= tempStr.toInt();
        //QString temp_Month = m_StringDate.Mid(5,2);
        m_Month = res.at(1).toInt();
        //QString temp_Day = m_StringDate.Mid(8,2);
        m_Day = res.at(2).toInt();

    };

    bool InFiveMinute(HSTimer otherTimer){
        if (otherTimer.m_Hour == m_Hour)
        {
            // 同一小时之内
            if ( m_Minute = otherTimer.m_Minute)
            {
            }
            else if (m_Minute != otherTimer.m_Minute)
            {

            }
        }
        else if ( abs(otherTimer.m_Hour - m_Hour) == 1 )
        {
            // 跨小时
        }

    };
};

}





//struct  StrategyData
//{
//public:
//    StrategyData(){
//        ID = -1;CODE = "";
//        HSTIME  = "";HSDATE = "";
//        OpenPrice = 0; ClosePrice =0;
//        HightPrice = 0; LowPrice =0;
//        BuyVolume = 0; SellVolume =0;
//        TradeVolume =0;HoldPosition=0;

//    };



//    StrategyData(vector<QString> inputData){
//        //ID = inputData.at(0);
//        ID = _ttoi(inputData.at(0));
//        CODE = inputData.at(1);
//        HSTIME = inputData.at(30);
//        HSDATE = inputData.at(50);

//        timer.SetData(HSTIME,HSDATE);

//        // QString 转 float
//        OpenPrice = _tstof(inputData.at(3));
//        ClosePrice = _tstof(inputData.at(7));

//        SellPrice = _tstof(inputData.at(4));
//        BuyPrice = _tstof(inputData.at(5));

//        SellVolume = _ttoi(inputData.at(8));
//        BuyVolume = _ttoi(inputData.at(9));

//        HightPrice = _tstof(inputData.at(11));
//        LowPrice = _tstof(inputData.at(12));

//        AveragePrice = _tstof(inputData.at(13));
//        TradeVolume = _ttoi(inputData.at(15));
//        HoldPosition = _ttoi(inputData.at(16));

//        UpLimitPrice = _tstof(inputData.at(18));
//        DownLimitPrice = _tstof(inputData.at(19));
//    };

//    int ID;// ID
//    QString CODE;// 编码
//    QString HSTIME;// 恒生时间
//    QString HSDATE;// 恒生日期

//    HSTimer timer;

//    float OpenPrice;//开盘价
//    float ClosePrice;// 收盘价
//    float HightPrice;// 最高价
//    float LowPrice;// 最低价
//    float AveragePrice;// 均价

//    float SellPrice;
//    float BuyPrice;

//    float UpLimitPrice;
//    float DownLimitPrice;

//    int BuyVolume;// 买量
//    int SellVolume; // 卖量

//    int TradeVolume;// 交易量
//    int HoldPosition;// 持仓量


//};


enum OPENCLOSE
{
    OPEN = 0,
    CLOSE,
    UNKNOWORDER
};

enum BUYSELL
{
    BUY = 0,
    SELL,
    UNKNOW

};

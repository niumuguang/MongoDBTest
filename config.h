#ifndef MD_CONFIG_H_
#define MD_CONFIG_H_

#define HOST "localhost"
////#define USER "lio"
////#define DatabaseUSER "lio"
//#define USER "root"
//#define PORT 3306
////#define PASSWD "root"
//#define PASSWD "niumuguang"
//#define DBNAME "FutureDB"
//#define CHARSET "utf8"
////#define STANDARDIP "116.236.239.129"

#pragma once

//请求编号
int requestId=0;

// 前置地址
char mdFront[]   ="tcp://asp-sim1-front1.financial-trading-platform.com:41213";
char tradeFront[]="tcp://asp-sim1-front1.financial-trading-platform.com:41205";
char riskFront[] ="tcp://asp-sim1-front1.financial-trading-platform.com:50001";

// 应用单元
//char	appId[] = "2030";			
//char userId[] = "0000000624";		
//char riskUser[]="demo";		
//char  passwd[] = "asdfgh";	



#endif



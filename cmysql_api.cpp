#include "cmysql_api.h"

using namespace std;

CMySQL_Api::CMySQL_Api()
{
    mysql_init(&m_mysql);
}

CMySQL_Api::CMySQL_Api(string username, string password, string database, string tablename)
{
    mysql_init(&m_mysql);
    m_user = username;
    m_passwd = password;
    m_database = database;
    m_table = tablename;
    //this->String2CharPt()
    mysql_real_connect(&m_mysql, "localhost", m_user.c_str(),
                       m_passwd.c_str(), m_database.c_str(), 3306, NULL, 0);

}

/****************************/
CMySQL_Api::CMySQL_Api(string ipaddress, int port,
                       string username, string password,
                       string database, string tablename)
{
    mysql_init(&m_mysql);
    m_user = username;
    m_passwd = password;
    m_database = database;
    m_table = tablename;
    m_address = ipaddress;
    m_port = port;
    mysql_real_connect(&m_mysql, m_address.c_str(), m_user.c_str(),
                       m_passwd.c_str(),
                       m_database.c_str(), port, NULL, 0);

}

CMySQL_Api::~CMySQL_Api()
{
    mysql_close(&m_mysql);
}


bool CMySQL_Api::IsConnect()
{
    if( !&m_mysql )
    {
        return false;
    }
    else
    {
        return true;
    }
}

int CMySQL_Api::Testing()
{
    string sql = "insert into ag1409 (InstrumentID) values ('java1');";
    int res = mysql_query(&m_mysql, sql.c_str());
    return res;
}

char *CMySQL_Api::String2CharPt(string inputData)
{
    string str=inputData;
    char * pstr=new char [str.length()+1];

    return pstr;
}

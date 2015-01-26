//MySQLManager_main.cpp
#include "MySQLManager.h"
int main()
{
  string host = "localhost";
  string user = "testuser";
  string pass = "test123";
  string db   = "TESTDB";
  string cmd   = "select * from EMPLOYEE";
  unsigned int port  = 3306;
  vector< vector<string> > result; 
  MySQLManager *mysqlmg=new MySQLManager(host,user,pass,db,port);
  mysqlmg->initConnection();
  mysqlmg->runSQLCommand(cmd);
  result=mysqlmg->getResult();
  for(vector<string> s: result){
    for(std::string s1: s){
   	std::cout<< s1 <<"\t";
    }
   std::cout<<endl;
  }
  
}

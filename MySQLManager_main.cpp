//MySQLManager_main.cpp
#include "MySQLManager.h"
#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

int main()
{
  string host = "localhost";
  string user = "testuser";
  string pass = "test123";
  string db   = "TESTDB";
  string cmd   = "select * from EMPLOYEE";
  unsigned int port  = 3306;
  vector< vector<string> > result; 
  std::cout << "running....\n";
  MySQLManager *mysqlmg=new MySQLManager(host,user,pass,db,port);
  mysqlmg->initConnection();

  
   try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
                    mysqlmg->runSQLCommand("select * from  EMPLOYEE;");
  			result=mysqlmg->getResult();
 			 for(vector<string> s: result){
   				 for(std::string s1: s){
   					std::cout<< s1 <<"\t";
     					new_sock << s1<<"\t";
   				 }
   			new_sock<<"\n";
 			 }
		  
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  
}

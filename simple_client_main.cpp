//simple_client_main.cpp
#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include "MySQLManager.h" 

int main ( int argc, char * argv[] )
{
  while(true)
  {
  std::string message="Test message of lishuai!";
  std::cout<<"please input string:";
  std::cin>>message;
  try
    {

      ClientSocket client_socket ( "192.168.1.36", 30000 );

      std::string reply;

      try
	{
	  client_socket << message;
	  client_socket >> reply;
	}
      catch ( SocketException& ) {}

      std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  }
  return 0;
}

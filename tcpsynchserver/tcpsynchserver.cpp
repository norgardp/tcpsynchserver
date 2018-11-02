// tcpsynchserver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	unsigned int port_number{ 3333 };
	try {
		Server srv;
		srv.Start(port_number);
		for (int i{ 0 }; i < 6; i++)
		{
			std::cout << "Listening for a connection " << i << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(10));
		}
		std::cout << "Ears closing." << std::endl;
		srv.Stop();
		std::cout << "Ears closed." << std::endl;
	}
	catch (std::system_error& e)
	{
		std::cout << "Error " << e.code() << " occurred." << std::endl;
		std::cout << "Error Message: " << e.what() << std::endl;
	}
	
    return 0;
}


#include "stdafx.h"
#include "Service.h"


Service::Service()
{
}


Service::~Service()
{
}


void Service::HandleClient(boost::asio::ip::tcp::socket& sock)
{
	try {
		// get request
		boost::asio::streambuf request;
		boost::asio::read_until(sock, request, '\n');

		// emulate the server doing something
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		// send response
		std::string response{ "Response\n" };
		boost::asio::write(sock, boost::asio::buffer(response));
	}
	catch (std::system_error& e ) {
		std::cout << "Error " << e.code() << " occurred." << std::endl;
		std::cout << "Error Message: " << e.what() << std::endl;
	}
}

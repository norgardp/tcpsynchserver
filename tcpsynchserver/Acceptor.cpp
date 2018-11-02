#include "stdafx.h"
#include "Acceptor.h"


//Acceptor::Acceptor()
//{
//}


Acceptor::~Acceptor()
{
}


void Acceptor::Accept()
{
	boost::asio::ip::tcp::socket sock(ios);
	acceptor.accept(sock);
	Service svc;
	svc.HandleClient(sock);
}


Acceptor::Acceptor(boost::asio::io_service& ios, unsigned int port_no) :
	ios(ios), acceptor(ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::address_v4::any(), port_no))
{
	acceptor.listen();
}

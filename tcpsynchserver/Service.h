#pragma once
class Service
{
public:
	Service();
	~Service();
	void HandleClient(boost::asio::ip::tcp::socket& sock);
};


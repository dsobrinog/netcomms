#include "asio_socket_api.h"
#include <netcomms/asiocomms/asio_center.h>


using namespace asiocomms;

asiocomms::asio_socket_api::asio_socket_api(asio_center *asio_center)
{
    asio_center_ = asio_center;
}

asiocomms::asio_socket_api::~asio_socket_api()
{

}

asio::ip::address asio_socket_api::make_adress(const std::string& local_ip)
{
    asio::error_code ec;
    auto address = asio::ip::make_address(local_ip, ec);
    if (ec)
    {
        std::cerr << "Invalid IP address: " << local_ip << " - " << ec.message() << std::endl;
        return asio::ip::address {};
    }

    return address;
}

void asio_socket_api::handle_connect(const asio::error_code& error)
{
    if (!error)
    {
        // Start read or write operations.

    }
    else
    {
        // Handle error.
        std::cerr << "Error while trying to connect socket: " << error.message() << std::endl;
    }
}


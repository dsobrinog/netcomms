#include "asio_socket_api.h"
#include <netcomms/asiocomms/asio_center.h>


using namespace asiocomms;

asiocomms::asio_socket_api::asio_socket_api(asio_center *asio_center)
{
}

void asio_socket_api::init(const std::string &local_ip, unsigned short local_port)
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


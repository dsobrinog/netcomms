#include "asio_udp_socket.h"
#include <netcomms/asiocomms/asio_center.h>

using namespace asiocomms;
using asio::ip::udp;

asio_udp_socket::asio_udp_socket(asio_center* center) : asio_socket_api(center)
{
    
}

void asio_udp_socket::init(const std::string &local_ip, unsigned short local_port)
{
    local_endpoint_= udp::endpoint(make_adress(local_ip), local_port);
    socketType = SocketType::UDP;
}

void asio_udp_socket::open()
{

}

void asio_udp_socket::bind()
{
    
}

void asio_udp_socket::connect(const std::string& remote_ip, unsigned short remote_port)
{
    
}


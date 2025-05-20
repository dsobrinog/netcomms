#include "asio_udp_socket.h"
#include <netcomms/asiocomms/asio_center.h>

using namespace asiocomms;
using asio::ip::udp;

asio_udp_socket::asio_udp_socket(asio_center* center) : asio_socket_api(center), socket_(center->get_io_context())
{
    socketType = SocketType::UDP;
}

void asio_udp_socket::init()
{
    
}

void asio_udp_socket::open()
{
    if(!socket_.is_open())
    {
        // Specify the protocol (IPv4 or IPv6) 
        socket_.open(asio::ip::udp::v4());
    }

}

void asio_udp_socket::bind(const std::string &local_ip, unsigned short local_port)
{
    local_endpoint_= udp::endpoint(make_adress(local_ip), local_port);
    socket_.bind(local_endpoint_);
}

void asio_udp_socket::connect(const std::string& remote_ip, unsigned short remote_port)
{
    remote_endpoint_ = udp::endpoint(make_adress(remote_ip), remote_port);
    socket_.connect(remote_endpoint_);
}

void asio_udp_socket::start_send()
{
    
}

void asio_udp_socket::start_receive()
{
    
}

void asio_udp_socket::close_socket()
{
    
}


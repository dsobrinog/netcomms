#include "asio_tcp_socket.h"

using namespace asiocomms;
using asio::ip::tcp;

asiocomms::asio_tcp_socket::asio_tcp_socket(asio_center *center)  : asio_socket_api(center)
{
}

void asio_tcp_socket::init()
{
    socketType = SocketType::TCP;
}


void asio_tcp_socket::open()
{
    
}

void asio_tcp_socket::bind(const std::string &local_ip, unsigned short local_port)
{
   endpoint_ = tcp::endpoint(asio::ip::make_address(local_ip), local_port);
}

void asio_tcp_socket::connect(const std::string& remote_ip, unsigned short remote_port)
{
    
}

void asio_tcp_socket::start_send()
{
    
}

void asio_tcp_socket::start_receive()
{
    
}

void asio_tcp_socket::close_socket()
{
    
}

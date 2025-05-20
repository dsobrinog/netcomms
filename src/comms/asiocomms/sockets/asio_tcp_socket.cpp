#include "asio_tcp_socket.h"

using namespace asiocomms;
using asio::ip::tcp;

void asio_tcp_socket::init(const std::string& local_ip, unsigned short local_port)
{
    endpoint_ = tcp::endpoint(asio::ip::make_address(local_ip), local_port);
    socketType = SocketType::TCP;
}


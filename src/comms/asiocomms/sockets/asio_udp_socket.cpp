#include "asio_udp_socket.h"

using namespace asiocomms;
using asio::ip::udp;

void asio_udp_socket::init(const std::string& local_ip, unsigned short local_port)
{
    endpoint_ = udp::endpoint(asio::ip::make_address(local_ip), local_port);
    socketType = SocketType::UDP;
}


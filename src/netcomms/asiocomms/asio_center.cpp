#include "asio_center.h"

#include <netcomms/asiocomms/sockets/asio_udp_socket.h>
#include <netcomms/asiocomms/sockets/asio_tcp_socket.h>

using namespace asiocomms;

asio_center::asio_center()
{
    // Open a thread for io_context to run
    worker_thread_ = std::thread([this]() { io_context_.run(); });
}

asio_center::~asio_center()
{
    // Stop io_context
    io_context_.stop();

    // Close thread
    if (worker_thread_.joinable())
    {
        worker_thread_.join();
    }
}

void asio_center::init()
{

}

asio_socket_api* asio_center::create_udp_socket(IPConfig config)
{
    
    return nullptr;
}

asio_socket_api* asio_center::create_tcp_socket(IPConfig config)
{
    return nullptr;
}

void asio_center::close_socket(asio_socket_api *socket_)
{
    socket_->close_socket();
}

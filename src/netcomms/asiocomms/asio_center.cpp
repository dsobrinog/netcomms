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
    auto udp_socket = std::make_unique<asio_udp_socket>(this);
    asio_socket_api* raw_ptr = udp_socket.get();
    active_sockets.push_back(std::move(udp_socket));
    return raw_ptr;
}

asio_socket_api* asio_center::create_tcp_socket(IPConfig config)
{
    auto tcp_socket = std::make_unique<asio_tcp_socket>(this);
    asio_tcp_socket* raw_ptr = tcp_socket.get();
    active_sockets.push_back(std::move(tcp_socket));
    return raw_ptr;
}

void asio_center::remove_socket(asio_socket_api *socket_)
{
    // Search for the socket
    auto it = std::find_if(active_sockets.begin(), active_sockets.end(),
        [socket_](const std::unique_ptr<asio_socket_api>& ptr) {
            return ptr.get() == socket_;
        });
    
    // Close and erase from the list
    if (it != active_sockets.end()) {
            socket_->close_socket();
            active_sockets.erase(it);
        }
}

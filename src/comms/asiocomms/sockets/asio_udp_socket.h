#ifndef ASIO_UDP_SOCKET
#define ASIO_UDP_SOCKET

#include <comms/asiocomms/sockets/asio_socket_api.h>
namespace asiocomms
{
    using asio::ip::udp;
    class asio_udp_socket : public asio_socket_api
    {
        asio_udp_socket();

        void init(const std::string& local_ip, unsigned short local_port);

        void open();
        void bind();
        void connect();

        protected:
        
            asio::ip::udp::socket socket_;
            asio::ip::udp::endpoint endpoint_;
    };
}


#endif
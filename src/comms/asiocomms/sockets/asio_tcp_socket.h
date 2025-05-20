#ifndef ASIO_TCP_SOCKET
#define ASIO_TCP_SOCKET

#include <comms/asiocomms/sockets/asio_socket_api.h>
namespace asiocomms
{
    using asio::ip::tcp;
    class asio_tcp_socket : public asio_socket_api
    {
        asio_tcp_socket();

        void init(const std::string& local_ip, unsigned short local_port);

        void open();
        void bind();
        void connect();
        
        protected:
            asio::ip::tcp::socket socket_;
            asio::ip::tcp::endpoint endpoint_;

    };

}


#endif
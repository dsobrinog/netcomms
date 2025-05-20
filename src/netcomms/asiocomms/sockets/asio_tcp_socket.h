#ifndef ASIO_TCP_SOCKET
#define ASIO_TCP_SOCKET

#include <netcomms/asiocomms/sockets/asio_socket_api.h>
namespace asiocomms
{
    
    using asio::ip::tcp;
    class asio_tcp_socket : public asio_socket_api
    {
        asio_tcp_socket(asio_center* center);

        void init(const std::string& local_ip, unsigned short local_port);

        void open();
        void bind();
        void connect(const std::string& remote_ip, unsigned short remote_port);

        // async
        virtual void start_send() = 0;
        virtual void start_receive() = 0;

        // closure
        virtual void close_socket() = 0;
        
        protected:
            asio::ip::tcp::socket* socket_;
            asio::ip::tcp::endpoint endpoint_;

    };

}


#endif
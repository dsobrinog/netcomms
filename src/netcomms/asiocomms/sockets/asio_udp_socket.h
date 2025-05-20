#ifndef ASIO_UDP_SOCKET
#define ASIO_UDP_SOCKET

#include <netcomms/asiocomms/sockets/asio_socket_api.h>

namespace asiocomms
{
    using asio::ip::udp;
    class asio_udp_socket : public asio_socket_api
    {
        public:
            asio_udp_socket(asio_center* center);

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
        
            asio::ip::udp::socket* socket_;

            udp::endpoint local_endpoint_;
            udp::endpoint remote_endpoint_;
    };
}


#endif
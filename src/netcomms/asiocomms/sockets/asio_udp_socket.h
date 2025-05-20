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

            void init();

            void open();
            void bind(const std::string &local_ip, unsigned short local_port);
            void connect(const std::string& remote_ip, unsigned short remote_port);

            // async
            void start_send();
            void start_receive();

            // closure
            void close_socket();

        protected:
        
            asio::ip::udp::socket socket_;

            udp::endpoint local_endpoint_;
            udp::endpoint remote_endpoint_;
    };
}


#endif
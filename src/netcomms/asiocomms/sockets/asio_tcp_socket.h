#ifndef ASIO_TCP_SOCKET
#define ASIO_TCP_SOCKET

#include <netcomms/asiocomms/sockets/asio_socket_api.h>
namespace asiocomms
{
    
    using asio::ip::tcp;
    class asio_tcp_socket : public asio_socket_api
    {
        public:

            asio_tcp_socket(asio_center* center);

            void init();

            void open();
            void bind(const std::string& local_ip, unsigned short local_port);
            void connect(const std::string& remote_ip, unsigned short remote_port);

            // async
            void start_send();
            void start_receive();

            // closure
            void close_socket();
        
        protected:
            asio::ip::tcp::socket* socket_;
            asio::ip::tcp::endpoint endpoint_;

    };

}


#endif
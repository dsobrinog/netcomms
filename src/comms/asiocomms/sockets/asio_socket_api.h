#ifndef ASIO_SOCKET
#define ASIO_SOCKET

#include <asio.hpp>
#include <comms/asiocomms/asio_center.h>
#include <comms/asiocomms/sockets/asio_buffer.h>

// Abstraction Asio Socket 
namespace asiocomms
{
    using asio::ip::udp;

    enum class SocketType
    {
        UDP,
        TCP
    };

    enum class ConnectionStatus 
    {
        Disconnected,
        Connecting,
        Connected,
        Error
    };

    class asio_socket_api
    {
        public:
            asio_socket_api(asio_center* asio_center);
            ~asio_socket_api();

            // creation
            virtual void init(const std::string& local_ip, unsigned short local_port) = 0;
            void set_options();

            // basic socket operations
            virtual void open() = 0;
            virtual void bind() = 0;
            virtual void connect() = 0;

            // async
            virtual void start_send() = 0;
            virtual void start_receive() = 0;

            // closure
            void close_socket();

            // status
            ConnectionStatus connection_status;

        protected:
            asio_center* asio_center_;

            SocketType socketType;
    };
}

#endif
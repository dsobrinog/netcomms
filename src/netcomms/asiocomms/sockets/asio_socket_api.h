#ifndef ASIO_SOCKET
#define ASIO_SOCKET

#include <asio.hpp>
#include <netcomms/asiocomms/sockets/asio_buffer.h>

// Abstraction Asio UDP/TCP Sockets for Async Comms

namespace asiocomms
{
    class asio_center;

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

    struct IPConfig
    {
        const std::string& local_ip     = "127.0.0.1";
        unsigned short local_port       = 3000;

        const std::string& remote_ip    = "127.0.0.1";
        unsigned short remote_port      = 3001;
    };

    class asio_socket_api
    {
        public:
            asio_socket_api(asio_center* asio_center);
            ~asio_socket_api();

            // creation
            virtual void init() = 0;

            // basic socket operations
            virtual void open() = 0;
            virtual void bind(const std::string& local_ip, unsigned short local_port) = 0;
            virtual void connect(const std::string& remote_ip, unsigned short remote_port) = 0;

            // async
            virtual void start_send() = 0;
            virtual void start_receive() = 0;

            // closure
            virtual void close_socket() = 0;

            // status
            ConnectionStatus connection_status;

        protected:

            asio_center* asio_center_;

            SocketType socketType;


            // Make Adress
            asio::ip::address make_adress(const std::string& local_ip);

            // Handle connection
            void handle_connect(const asio::error_code& error);
    };
}

#endif
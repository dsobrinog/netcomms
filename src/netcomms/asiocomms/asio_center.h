#ifndef ASIO_CENTER
#define ASIO_CENTER

#include <asio.hpp>

#include <thread>
#include <iostream>

#include <vector>

#include <netcomms/asiocomms/sockets/asio_socket_api.h>

// Manager that creates and configure UDP sockets
namespace asiocomms
{
    struct IPConfig
    {
        const std::string& local_ip     = "127.0.0.1";
        unsigned short local_port       = 3000;
    };

    class asio_center
    {
        public:
            asio_center();
            ~asio_center();
            
            void init();

            // IO_CONTEXT
            inline asio::io_context& get_io_context() { return io_context_; }

            // Socket Management

            // Create UDP Socket
            asio_socket_api* create_udp_socket(IPConfig config);
            // Create TCP Socket
            asio_socket_api* create_tcp_socket(IPConfig config);
            // Close Socket
            void close_socket(asio_socket_api* socket_);


            // Async Operation management


            // Log (Errors, messages, warnings)

        private:
            asio::io_context io_context_;
            std::thread worker_thread_;

            std::vector<asio_socket_api*> active_sockets;
    };
}

#endif
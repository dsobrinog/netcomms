#ifndef ASIO_CENTER
#define ASIO_CENTER

#include <asio.hpp>

#include <thread>


// Manager that creates and configure UDP sockets
namespace asiocomms
{
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
            // Create TCP Socket
            // Close Socket


            // Async Operation management


            // Log (Errors, messages, warnings)

        private:
            asio::io_context io_context_;
            std::thread worker_thread_;
    };
}

#endif
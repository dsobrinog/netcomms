#ifndef ASIO_BUFFER
#define ASIO_BUFFER

#include <asio.hpp>

#include <memory>

// UDP Buffer 
namespace asiocomms
{
    using asio::ip::udp;

    constexpr int MAX_BUFFER_SIZE = 64000; // 64 Kb
    class asio_socket_api;

    class asio_buffer
    {
        public:
            asio_buffer(asio_socket_api* socket);
            ~asio_buffer();

            void init();
          
            void            write_data(const char* src, size_t len);
            const char*     read_data();

            inline int      get_buffer_size() { return size;}
            void            clear_buffer();
        
        private:
            asio_socket_api* socket_;

            // Data pack
            size_t size;
            std::unique_ptr<char[]> data;
    };
}

#endif
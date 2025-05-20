#include "asio_buffer.h"
#include <netcomms/asiocomms/sockets/asio_socket_api.h>

#include <iostream>



using namespace asiocomms;

asio_buffer::asio_buffer(asio_socket_api* socket)
{
    socket_ = socket;
    data = std::make_unique<char[]>(MAX_BUFFER_SIZE); 

}

void asio_buffer::init()
{
    clear_buffer();
}

void asio_buffer::write_data(const char* src, size_t len)
{
    if(len > MAX_BUFFER_SIZE) std::cout << "Buffer overflow" << std::endl;

    std::memcpy(data.get(), src, len);
}

const char *asio_buffer::read_data()
{
    return data.get();
}

void asio_buffer::clear_buffer()
{
    memset(data.get(), 0, size);
}

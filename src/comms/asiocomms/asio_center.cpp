#include "asio_center.h"


using namespace asiocomms;

asio_center::asio_center()
{
    // Open a thread for io_context to run
    worker_thread_ = std::thread([this]() { io_context_.run(); });
}

asio_center::~asio_center()
{
    // Stop io_context
    io_context_.stop();

    // Close thread
    if (worker_thread_.joinable())
    {
        worker_thread_.join();
    }
}

void asio_center::init()
{

}

#ifndef ZMQ_CENTER
#define ZMQ_CENTER

#include <zmq.hpp>

#include <netcomms/zmqcomms/sockets/zmq_socket_api.h>

#include <string>
#include <iostream>
#include <vector>


namespace zmqcomms
{
    static constexpr int ZMQ_THREADS = 1;

    class zmq_center
    {
        public:
            zmq_center();
            ~zmq_center();

            // Initialize ZMQ: Create ctx, report version
            void init();

            // Make sure all sockets/messages are closed before shutting down ZMQ
            void shut_down();

            // Socket life cycle
            zmq_socket_api* create_socket(SocketType _socketType);
            void destroy_socket(zmq_socket_api* _socket);

        protected:
            void create_context();
            void destroy_context();

            void show_version();

            zmq::context_t zmq_context;
            
            std::vector<zmq_socket_api*> active_sockets;
    };
}

#endif
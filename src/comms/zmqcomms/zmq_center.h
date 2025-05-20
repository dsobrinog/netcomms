#ifndef ZMQ_CENTER
#define ZMQ_CENTER

#include <zmq.hpp>

namespace zmqcomms
{
    static constexpr int ZMQ_THREADS = 1;

    class zmq_center
    {
        public:
            zmq_center();
            ~zmq_center();

            void init();
            void create_context();
    };
}

#endif
#include "zmq_center.h"

using namespace zmqcomms;

zmq_center::zmq_center()
{
}

zmq_center::~zmq_center()
{
}

void zmq_center::create_context()
{   
    // Creamos contexto
    zmq::context_t context(ZMQ_THREADS);
    
}
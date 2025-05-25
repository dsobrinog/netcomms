#include "zmq_center.h"

using namespace zmqcomms;

#include <netcomms/zmqcomms/sockets/zmq_socket_req.h>

zmq_center::zmq_center()
{
}

zmq_center::~zmq_center()
{
}

void zmq_center::init()
{
    create_context();
    show_version();
}

void zmq_center::shut_down()
{
    destroy_context();
}

// Factory design pattern
zmq_socket_api* zmq_center::create_socket(SocketType _socketType)
{
    std::cout << "Creating new socket of type "; 
    
    switch (_socketType) {
        case SocketType::REQUEST:
            std::cout << "request..." << std::endl; 
            return new zmq_socket_req(this);
        
        case SocketType::RESPONSE:
            return nullptr;

        default:
            throw std::invalid_argument("Unsupported socket type");
    }
   

    return nullptr;
}

void zmq_center::create_context()
{   
    // Creamos contexto
    zmq_context = zmq::context_t(ZMQ_THREADS);
}

void zmq_center::destroy_context()
{
    // Shut down sockets
    zmq_context.shutdown();
    // Terminate context
    zmq_context.close();
}

void zmq_center::show_version()
{
    int major, minor, patch;
    zmq_version (&major, &minor, &patch);  
    std::cout << "Current ZMQ version is " << major << '.' << minor << '.' << patch << '\n';
}
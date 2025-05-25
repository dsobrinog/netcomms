#include "zmq_socket_api.h"

#include <netcomms/zmqcomms/zmq_center.h>

using namespace zmqcomms;

zmq_socket_api::zmq_socket_api(zmq_center* _zmq_center)
{
    center = _zmq_center;
}
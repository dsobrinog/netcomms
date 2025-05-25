#include "zmq_socket_req.h"

using namespace zmqcomms;

zmq_socket_req::zmq_socket_req(zmq_center *_zmq_center) : zmq_socket_api(_zmq_center)
{

}

void zmq_socket_req::init(zmq::socket_type socketType)
{
}

void zmq_socket_req::open()
{
}

void zmq_socket_req::close()
{
}

void zmq_socket_req::set_configuration()
{
}

void zmq_socket_req::get_configuration()
{
}

void zmq_socket_req::bind(const std::string& local_ip, unsigned short local_port)
{
}
void zmq_socket_req::connect(const std::string& remote_ip, unsigned short remote_port)
{
}

void zmq_socket_req::start_send()
{
}

void zmq_socket_req::on_send_msg()
{
}

void zmq_socket_req::start_receive()
{
}

void zmq_socket_req::on_receive_msg()
{
}

void zmq_socket_req::create_msg()
{
}


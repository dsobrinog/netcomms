#ifndef ZMQ_SOCKET_REQ_H
#define ZMQ_SOCKET_REQ_H

#include <netcomms/zmqcomms/sockets/zmq_socket_api.h>

namespace zmqcomms
{
    class zmq_socket_req : public zmq_socket_api
    {
    
    public:

        zmq_socket_req(zmq_center* _zmq_center);
        ~zmq_socket_req();

         // creation
        void init(zmq::socket_type socketType);

        // basic socket operations
        void open();
        void close();

        void set_configuration();
        void get_configuration();

        void bind(const std::string& local_ip, unsigned short local_port);
        void connect(const std::string& remote_ip, unsigned short remote_port);

        // async connection
        void start_send();
        void on_send_msg();

        void start_receive();
        void on_receive_msg();

        // messaging
        void create_msg();

    };
}

#endif
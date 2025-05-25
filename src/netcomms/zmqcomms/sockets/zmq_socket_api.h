#ifndef ZMQ_SOCKET
#define ZMQ_SOCKET

#include <zmq.hpp>
#include <string>

namespace zmqcomms
{
    class zmq_center;

    enum class ConnectionStatus 
    {
        Disconnected,
        Connecting,
        Connected,
        Error
    };

    enum class SocketType
    {
        REQUEST,
        RESPONSE
    };

    struct IPConfig
    {
        const std::string& local_ip     = "127.0.0.1";
        unsigned short local_port       = 3000;

        const std::string& remote_ip    = "127.0.0.1";
        unsigned short remote_port      = 3001;
    };

    class zmq_socket_api
    {
        public:
            zmq_socket_api(zmq_center* _zmq_center);
            ~zmq_socket_api();

            // creation
            virtual void init(zmq::socket_type socketType) = 0;

            // basic socket operations
            virtual void open() = 0;
            virtual void close() = 0;

            virtual void set_configuration() = 0;
            virtual void get_configuration() = 0;

            virtual void bind(const std::string& local_ip, unsigned short local_port) = 0;
            virtual void connect(const std::string& remote_ip, unsigned short remote_port) = 0;

            // async connection
            virtual void start_send() = 0;
            virtual void on_send_msg() = 0;

            virtual void start_receive() = 0;
            virtual void on_receive_msg() = 0;

            // messaging
            virtual void create_msg() = 0;
            // Close msg

        protected:

            zmq_center* center;

            // req      = ZMQ_REQ,
            // rep      = ZMQ_REP,
            // dealer   = ZMQ_DEALER,
            // router   = ZMQ_ROUTER,
            // pub      = ZMQ_PUB,
            // sub      = ZMQ_SUB,
            // xpub     = ZMQ_XPUB,
            // xsub     = ZMQ_XSUB,
            // push     = ZMQ_PUSH,
            // pull     = ZMQ_PULL,
            zmq::socket_type socketType;

            
            // Disconnected,
            // Connecting,
            // Connected,
            // Error
            ConnectionStatus connection_status;
    };
}

#endif
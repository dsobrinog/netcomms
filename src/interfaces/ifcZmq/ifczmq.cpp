#include "ifczmq.h"

cl_ifcZmq::cl_ifcZmq(int moduleId, Executive * _exec) : cl_module(moduleId, _exec)
{
    std::cout << "ifc zmq constructor..." << std::endl;
}

cl_ifcZmq::~cl_ifcZmq()
{
    std::cout << "ifc zmq destructor..." << std::endl;
}


void cl_ifcZmq::init()
{
    std::cout << "ifc zmq constructor..." << std::endl;
}

void cl_ifcZmq::read()
{
    std::cout << "ifc zmq read..." << std::endl;
}
void cl_ifcZmq::write()
{
    std::cout << "ifc zmq write..." << std::endl;
}
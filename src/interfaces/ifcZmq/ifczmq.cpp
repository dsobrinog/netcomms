#include "ifczmq.h"

cl_ifczmq::cl_ifczmq(int moduleId, Executive * _exec) : cl_module(moduleId, _exec)
{
    std::cout << "ifc zmq constructor..." << std::endl;
}

cl_ifczmq::~cl_ifczmq()
{
    std::cout << "ifc zmq destructor..." << std::endl;
}


void cl_ifczmq::init()
{
    std::cout << "ifc zmq constructor..." << std::endl;
}

void cl_ifczmq::read()
{
    std::cout << "ifc zmq read..." << std::endl;
}
void cl_ifczmq::write()
{
    std::cout << "ifc zmq write..." << std::endl;
}
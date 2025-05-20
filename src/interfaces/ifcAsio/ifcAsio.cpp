#include "ifcAsio.h"

cl_ifcAsio::cl_ifcAsio(int moduleId, Executive* _exec) : cl_module(moduleId, _exec)
{
    std::cout << "ifc asio constructor..." << std::endl;
}

cl_ifcAsio::~cl_ifcAsio()
{

}

void cl_ifcAsio::init()
{
    std::cout << "ifc asio init..." << std::endl;

    asio::io_context io;
}

void cl_ifcAsio::read()
{
    std::cout << "ifc asio read..." << std::endl;
}
void cl_ifcAsio::write()
{
    std::cout << "ifc asio write..." << std::endl;
}


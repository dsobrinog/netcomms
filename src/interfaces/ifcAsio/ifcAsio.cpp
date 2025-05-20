#include "ifcAsio.h"

cl_ifcasio::cl_ifcasio(int moduleId, Executive* _exec) : cl_module(moduleId, _exec)
{
    std::cout << "ifc asio constructor..." << std::endl;
}

cl_ifcasio::~cl_ifcasio()
{

}

void cl_ifcasio::init()
{
    std::cout << "ifc asio init..." << std::endl;

    asio::io_context io;
}

void cl_ifcasio::read()
{
    std::cout << "ifc asio read..." << std::endl;
}
void cl_ifcasio::write()
{
    std::cout << "ifc asio write..." << std::endl;
}


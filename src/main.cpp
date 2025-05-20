#include <iostream>
#include <zmq.hpp>

#include "core/executive.h"

#include "interfaces/ifcZmq/ifczmq.h"
#include "interfaces/ifcAsio/ifcAsio.h"



Executive* _exec; 

int module_id = 0;

int main() {

    std::cout << "Starting Executive..." << std::endl;
    _exec = new Executive;

    std::cout << "Adding modules..." << std::endl;
    cl_ifczmq* moduleZmq = new cl_ifczmq(module_id++, _exec);
    cl_ifcasio* moduleAsio = new cl_ifcasio(module_id++, _exec);

    _exec->add_module(moduleZmq);
    _exec->add_module(moduleAsio);

    std::cout << "Initializing Executive..." << std::endl;
    _exec->init();

    std::cout << "Begining Execution..." << std::endl;
    while (_exec->in_execution())
    {
        _exec->execute_cycle();
    }

    _exec->end_simulation();


    return 0;
}



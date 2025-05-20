#ifndef IFCZMQ_H
#define IFCZMQ_H

#include "core/module.h"
#include "comms/zmqcomms/zmq_center.h"

class cl_ifczmq : public cl_module
{
public:
    cl_ifczmq(int moduleId, Executive* _exec);
    ~cl_ifczmq();

    void init();
    void read();
    void write();

private:
    Executive* exec;
    zmqcomms::zmq_center* zmqCenter;

};


#endif
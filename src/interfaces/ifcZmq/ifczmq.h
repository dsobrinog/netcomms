#ifndef IFCZMQ_H
#define IFCZMQ_H

#include "core/module.h"
#include "netcomms/zmqcomms/zmq_center.h"

class cl_ifcZmq : public cl_module
{
public:
    cl_ifcZmq(int moduleId, Executive* _exec);
    ~cl_ifcZmq();

    void init();
    void read();
    void write();

private:
    Executive* exec;
    zmqcomms::zmq_center* zmqCenter;

};


#endif
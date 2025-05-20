
#ifndef IFCASIO_H

#include <asio.hpp>
#include <core/module.h>
#include <comms/asiocomms/asio_center.h>

class cl_ifcasio : public cl_module
{
public:
    cl_ifcasio(int moduleId, Executive* _exec);
    ~cl_ifcasio();

    void init();
    void read();
    void write();

private:
    Executive* exec;
    asiocomms::asio_center asio_cntr;
};

#endif

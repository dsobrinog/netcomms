
#ifndef IFCASIO_H

#include <asio.hpp>
#include <core/module.h>
#include <netcomms/asiocomms/asio_center.h>

class cl_ifcAsio : public cl_module
{
public:
    cl_ifcAsio(int moduleId, Executive* _exec);
    ~cl_ifcAsio();

    void init();
    void read();
    void write();

private:
    Executive* exec;
    asiocomms::asio_center asio_center_;
};

#endif

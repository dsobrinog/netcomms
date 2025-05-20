#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <iostream>
#include <cstdint>


class Executive;

class cl_module
{
    std::string ipSource    = "127.0.0.1::5001";
    std::string ipDest      = "127.0.0.1::6001";
    
public:
    cl_module(int moduleId, Executive* _exec);

    virtual void init() = 0;
    
    virtual void run();
    virtual void read() = 0;
    virtual void write() = 0;

    void set_source_ip(std::string sourceIp);
    void set_dest_ip(std::string sourceDest);

    inline int get_module_id(){return moduleId;}

    bool first_execution();
    
private:
    Executive* exec;

    int moduleId = 0;
    uint64_t prev_cycle = -1;
};

#endif
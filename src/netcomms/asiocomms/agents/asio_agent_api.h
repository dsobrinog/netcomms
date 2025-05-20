#ifndef ASIO_AGENT
#define ASIO_AGENT

#include <asio.hpp>


class asio_agent_api
{
    // Agent: 
    // https://think-async.com/Asio/asio-1.30.2/doc/asio/overview/model/async_agents.html

    virtual void start_agent();
    virtual void finish_agent();


    // Composition of async operations (FSM arquetype)

    // Add an async operation

    // Remove an async operation

    // Reorder async operation

    // Current async operation

    // Selection of the next asyn operation (deterministic, heuristic...) 

    // Conditions to transition into the next async operation


    //////////////////
    // https://think-async.com/Asio/asio-1.30.2/doc/asio/overview/model/associators.htm

    // Associated Characteristics that definy async operation behave

    // Allocator

    // Cancelation slot

    // Executor

    //////////////////
    //  Associators: 


    //////////////////

    // Child agents:
    // https://think-async.com/Asio/asio-1.30.2/doc/asio/overview/model/child_agents.html
};

#endif
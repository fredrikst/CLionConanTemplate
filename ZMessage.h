#ifndef CLIONCONANTEMPLATE_ZMESSAGE_H
#define CLIONCONANTEMPLATE_ZMESSAGE_H

#include <zmq.hpp>
#include <vector>

class ZMessage {
public:
    void add(const void* data, size_t size);
    void send(zmq::socket_t& socket);

private:
    std::vector<zmq::message_t> messages_;
};

#endif
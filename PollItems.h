#ifndef CLIONCONANTEMPLATE_POLLITEMS_H
#define CLIONCONANTEMPLATE_POLLITEMS_H

#include <vector>
#include <zmq.hpp>

class PollItems {
public:
    void addItem(void* socket, short events);
    void addItem(void* socket, int fd, short events);
    int poll();
private:
    std::vector<zmq::pollitem_t> pollItems_;
};


#endif

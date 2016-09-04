#include "PollItems.h"

void PollItems::addItem(void* socket, short events) {
    pollItems_.push_back(zmq_pollitem_t {socket, 0, events, 0});
}

void PollItems::addItem(void* socket, int fd, short events) {
    pollItems_.push_back(zmq_pollitem_t {socket, fd, events, 0});
}

int PollItems::poll() {
    return zmq::poll(&pollItems_[0], pollItems_.size());
}

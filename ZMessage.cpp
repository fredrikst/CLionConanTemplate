#include "ZMessage.h"

void ZMessage::add(const void* data, size_t size) {

    zmq::message_t message(size);
    memcpy(message.data(), data, size);

    messages_.emplace_back(std::move(message));
}

void ZMessage::send(zmq::socket_t& socket) {

    for (int i = 0; i < messages_.size(); ++i) {

        bool sendMore = (i + 1) < messages_.size();
        socket.send(messages_[i],  sendMore ? ZMQ_SNDMORE : 0);
    }
}



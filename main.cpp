#include <iostream>
#include <zmq.hpp>
#include <thread>
#include "PollItems.h"
#include "ZMessage.h"

using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::thread;
using std::string;
using std::chrono::seconds;

void zmq_thread(zmq::context_t* context) {
    zmq::socket_t socket(*context, ZMQ_PAIR);
    socket.bind("inproc://thread");

    PollItems pollItems;
    pollItems.addItem(socket, ZMQ_POLLIN);

    bool more;

    while (true) {
        pollItems.poll();

        do {

            zmq::message_t request;
            socket.recv (&request);

            cout << static_cast<char*>(request.data()) << endl;

            more = request.more();

        } while(more);

        string message = "Pong";
        socket.send(message.c_str(), message.size());

        sleep_for(seconds(3));
    }
}

int main() {

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PAIR);

    thread t(zmq_thread, &context);

    socket.connect("inproc://thread");

    while (true) {

        ZMessage message;
        message.add("Ping1", 5);
        message.add("Ping2", 5);
        message.add("Ping3", 5);
        message.send(socket);

        zmq::message_t request;
        socket.recv(&request);
        cout << static_cast<char*>(request.data()) << std::endl;
        sleep_for(std::chrono::seconds(3));
    }
}
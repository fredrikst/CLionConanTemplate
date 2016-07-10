#include <iostream>
#include <zmq.hpp>
#include <thread>

using namespace std;

void zmq_thread(zmq::context_t* context) {
    zmq::socket_t socket(*context, ZMQ_PAIR);
    socket.bind("inproc://thread");

    while (true) {
        zmq::message_t request;
        socket.recv (&request); //  Wait for next request from client
        std::cout << "Thread Received" << std::endl;

        std::string message = "";
        socket.send(message.c_str(), message.size());

        std::this_thread::sleep_for (std::chrono::seconds(3));
    }
}

int main() {

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PAIR);

    std::thread t(zmq_thread, &context);

    socket.connect("inproc://thread");

    while (true) {
        std::string message = "";
        socket.send(message.c_str(), message.size());

        zmq::message_t request;
        socket.recv(&request);
        std::cout << "Main Received" << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(3));
    }

    t.join();
    return 0;
}
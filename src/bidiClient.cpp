//
// Created by nadavyaf@wincs.cs.bgu.ac.il on 03/01/2022.
//
#include "../include/Task.h"
#include "../include/encoderDecoder.h"
#include "../include/connectionHandler.h"
#include <iostream>
#include <ostream>
#include <string>

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }
    encoderDecoder enc;
    std::mutex mutex;
    Task task1(1, mutex);
    std::thread th1(&Task::run, &task1);
    //From here we will see the rest of the echo client implementation:
    while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        std::string sendLine = enc.encode(line);
        int len = sendLine.length();
        if (!connectionHandler.sendLine(sendLine)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        return 0;
    }
}

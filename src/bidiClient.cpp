#include <stdlib.h>
#include "../include/Task.h"
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
    Task task1(host,port);
    std::thread th1(&Task::run, &task1);
    std::mutex mtx;
    std::unique_lock<std::mutex> lk (mtx);
    //From here we will see the rest of the echo client implementation:
    while (!connectionHandler.getProt().shouldTerminate()) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        std::string sendLine = connectionHandler.getEnc().encode(line);
        int len = sendLine.length();
        if (!connectionHandler.sendLine(sendLine)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            connectionHandler.getProt().setTerminate(true);
            break;
        }
        if (sendLine=="3"){
            task1.getCv().wait(lk);
        }
        std::cout << "Sent " << len + 1 << " bytes to server" << std::endl;
    }
}
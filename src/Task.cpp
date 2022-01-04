#include "../include/Task.h"
Task::Task (int id,std::mutex& mutex,std::string host,short port): _id(id), _mutex(mutex),_host(std::move(host)),_port(port),_handler(_host,_port){}
void Task::run(){
    std::vector<char> bytes;
    while (!_handler.getProt().shouldTerminate()) {
        if (!_handler.getLine(bytes)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
    }
}

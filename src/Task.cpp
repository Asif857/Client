#include "../include/Task.h"
Task::Task (std::string host,short port):_host(std::move(host)),_port(port),_handler(_host,_port),cv(){}
void Task::run(){
    std::vector<char> bytes;
    while (!_handler.getProt().shouldTerminate()) {
        if (!_handler.getLine(bytes)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
    }
    cv.notify_all();
}
std::condition_variable &Task::getCv()  {
    return cv;
}


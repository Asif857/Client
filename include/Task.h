//
// Created by rolantas@wincs.cs.bgu.ac.il on 02/01/2022.
//
#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#include "connectionHandler.h"

class Task{
private:
    int _id;
    std::mutex & _mutex;
    std::string _host;
    short _port;
    ConnectionHandler _handler;

public:
    Task (int id,std::mutex& mutex,std::string host,short port);
    void run();
};
#endif

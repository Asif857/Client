//
// Created by rolantas@wincs.cs.bgu.ac.il on 02/01/2022.
//
#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <mutex>
#include <thread>
#include "connectionHandler.h"

class Task{
private:
    int _id;
    std::mutex & _mutex;
    ConnectionHandler _handler;

public:
    Task (int id,std::mutex& mutex, short port, std::string host);
    void run(){}
};
#endif

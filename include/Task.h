//
// Created by rolantas@wincs.cs.bgu.ac.il on 02/01/2022.
//
#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <mutex>
#include <thread>
#include "../../SPL3new/include/connectionHandler.h"
class Task{
private:
    int _id;
    std::mutex & _mutex;
    ConnectionHandler handler;

public:
    Task (int id,std::mutex& mutex) : _id(id), _mutex(mutex){}
    void run(){}
};
#endif

//
//
//
#ifndef BIDIPROTOCOL_H
#define BIDIPROTOCOL_H
#include <string>
class bidiProtocol{
public:
    bidiProtocol();
    std::string cutString(int index, std::string message);
    void process(std::string message);
};


#endif


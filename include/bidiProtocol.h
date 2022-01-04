//
//
//
#ifndef BIDIPROTOCOL_H
#define BIDIPROTOCOL_H
#include <string>
class bidiProtocol{
private:
    bool terminate;
public:
    bidiProtocol();
    std::string cutString(int index, std::string message);
    void process(std::string message);
    bool shouldTerminate() const;
};


#endif


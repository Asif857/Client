//
// Created by rolantas@wincs.cs.bgu.ac.il on 02/01/2022.
//
#ifndef ENCODERDECODER_H
#define ENCODERDECODER_H
#include <string>
#include <vector>

class encoderDecoder {
public:
    encoderDecoder();
    std::string decode (std::vector<char> bytes);
    std::string encode(std::string message);
    void shortToBytes(short num, char* bytesArr);
    short bytesToShort(char* bytesArr);
    void printstuff(std::vector<int> yop);
};
#endif

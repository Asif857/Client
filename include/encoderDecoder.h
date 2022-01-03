//
// Created by rolantas@wincs.cs.bgu.ac.il on 02/01/2022.
//
#ifndef ENCODERDECODER_H
#define ENCODERDECODER_H
#include <string>
class encoderDecoder {
public:
    encoderDecoder();
    void decodeString (unsigned char* point,std::string message);
    std::string encode(std::string message);
    void shortToBytes(short num, char* bytesArr);
    short bytesToShort(char* bytesArr);
    void printstuff();
};
#endif

#include "../include/encoderDecoder.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>

void encoderDecoder::decodeString(unsigned char *point, std::string message) {
   point = new unsigned char[message.length()+1];
   strcpy((char *)point,message.c_str());
}
void encoderDecoder::printstuff() {

    std::cout<<"yo";
}

encoderDecoder::encoderDecoder() {
}

std::string encoderDecoder::encode(std::string msg) {
    std::stringstream s(msg);
}

void encoderDecoder::shortToBytes(short num, char *bytesArr) {
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}
short encoderDecoder::bytesToShort(char* bytesArr)
{
    short result = (short)((bytesArr[0] & 0xff) << 8);
    result += (short)(bytesArr[1] & 0xff);
    return result;
}

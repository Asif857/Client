#include "../include/encoderDecoder.h"
#include <iostream>
#include <sstream>
#include <vector>
encoderDecoder::encoderDecoder() {
}

std::string encoderDecoder::encode(std::string msg) {
    std::stringstream s(msg);
    std::vector<std::string> ans;
    std::string tmp;
    int i =0;
    while (getline(s,tmp,' ')){
        ans.push_back(tmp);
        i++;
    }
    if (ans[0]=="REGISTER"){
        ans[0]="1";

    }
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

//std::string encoderDecoder::decodeString(std::string message) {
//}

void encoderDecoder::printstuff(std::vector<int> yop) {
yop.push_back(1);
}

std::string encoderDecoder::decode(std::vector<char> bytes) {
    std::string ans="";
    char bytesarr[2];
    bytesarr[0] = bytes[0];
    bytesarr[1] = bytes[1];
    short opcode = bytesToShort(bytesarr);
    return ans;
}

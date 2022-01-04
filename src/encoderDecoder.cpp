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

std::string encoderDecoder::decode(std::vector<char> bytes) {
    std::string ans;
    char bytesArr[2];
    bytesArr[0] = bytes[0];
    bytesArr[1] = bytes[1];
    short opcode = bytesToShort(bytesArr);
    std::string strOpcode = std::to_string(opcode);
    ans.append(strOpcode);
    //Notification
    if(opcode == 9){
        char typeArr[1];
        typeArr[0] = bytes[2];
        short type = bytesToShort(typeArr);
        std::string strType = std::to_string(type);
        int index = 3;
        char byteIndex = bytes[index];
        while(byteIndex != '\0'){
            std::string stringIndex = std::to_string(byteIndex);
            ans.append(stringIndex);
            index++;
            byteIndex=bytes[index];
        }
        ans.append(std::to_string('/0'));
        index++;
        byteIndex = bytes[index];
        while(byteIndex != '\0'){
            std::string stringIndex = std::to_string(byteIndex);
            ans.append(stringIndex);
            index++;
            byteIndex=bytes[index];
        }
        ans.append(std::to_string('/0'));
        return ans;
    }
    //ACK
    else if(opcode == 10){
        char ackBytesArr[2];
        ackBytesArr[0] = bytes[2];
        ackBytesArr[1] = bytes[3];
        short messOpcode = bytesToShort(ackBytesArr);
        std::string strMessageOpcode = std::to_string(messOpcode);
        ans.append(strMessageOpcode);
        if(bytes.size()>5){
           for(int i=4;i<bytes.size();i++){
               char byteChar = bytes[i];
               std::string ansChar = std::to_string(byteChar);
               ans.append(ansChar);
           }
        }
        return ans;
    }
    //Error
    else if(opcode == 11){
        char errBytesArr[2];
        errBytesArr[0] = bytes[2];
        errBytesArr[1] = bytes[3];
        short errOpcode = bytesToShort(errBytesArr);
        std::string strErrOpcode = std::to_string(errOpcode);
        ans.append(strErrOpcode);
        return ans;
    }
    return ans;
}

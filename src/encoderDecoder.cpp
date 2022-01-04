#include "../include/encoderDecoder.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>

encoderDecoder::encoderDecoder() {
}

std::vector<char> encoderDecoder::encode(std::string msg) {
    std::stringstream s(msg);
    std::vector<std::string> ans;
    std::string tmp;
    std::vector<char> returned;
    char zero = '\0';
    int i =0;
    while (getline(s,tmp,' ')){
        ans.push_back(tmp);
        if (ans[0] == "POST" || (ans[0] == "PM" && i==1))
            break;
        i++;
    }
    char opBytes[2];
    short opcode;
    while (ans.size()<7) {
        ans.push_back("");
    }
    if (ans[0]=="REGISTER"){
        opcode = 1;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        std::string userName = ans[1];
        std::string pass = ans[2];
        std::string birthday = ans[3];
        for(char userChar: userName){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        for(char userChar: pass){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        for(char userChar: birthday){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        return returned;
    }
    else if (ans[0] == "LOGIN") {
        opcode = 2;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        std::string userName = ans[1];
        std::string pass = ans[2];
        std::string captcha = ans[3];
        for (char userChar: userName) {
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        for (char userChar: pass) {
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        for (char userChar: captcha) {
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        return returned;
    }
    else if (ans[0] == "LOGOUT"){
        opcode = 3;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        return returned;
    }
    else if (ans[0]=="FOLLOW"){
        opcode = 4;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        std::string follow = ans[1];
        std::string userName = ans[2];
        for (char userChar: follow) {
            returned.push_back(userChar);
        }
        for (char userChar: userName) {
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        return returned;
    }
    else if (ans[0]=="POST"){
        opcode = 5;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        std::string content = msg.substr(5);
        for(char userChar: content){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        return returned;
    }
    else if (ans[0]=="PM") {
        opcode = 6;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        std::string userName = ans[1];
        std::string content=msg.substr(3+ans[1].length());
        for(char userChar: userName){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        for(char userChar: content){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%d-%m-%Y %H:%M");
        std::string str = oss.str();
        for(char userChar: str){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        return returned;
    }
    else if (ans[0] == "LOGSTAT"){
        opcode = 7;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        return returned;
    }
    else if (ans[0]=="STAT"){
        opcode = 8;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        std::string usernames = ans[1];
        for(char userChar: usernames){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
        return returned;
    }
    else if (ans[0] == "BLOCK"){
        opcode = 12;
        shortToBytes(opcode, opBytes);
        returned.push_back(opBytes[0]);
        returned.push_back(opBytes[1]);
        std::string username =ans[1];
        for(char userChar: username){
            returned.push_back(userChar);
        }
        returned.push_back(zero);
    }
    return returned;
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
    char getBytes[2];
    std::string ans;
    getBytes[0] = bytes[0];
    getBytes[1] = bytes[1];
    short opcode = bytesToShort(getBytes);
    std::string strOpcode = std::to_string(opcode);
    ans.append(strOpcode);
    //notification
    if(opcode == 9){
        short shortByte = bytes[2];
        ans.append(std::to_string(shortByte));
        int index = 3;
        char currByte = bytes[index];
        while(currByte != '\0'){
            ans += currByte;
            index++;
            currByte = bytes[index];
        }
        ans.append(std::to_string('\0'));
        index++;
        currByte = bytes[index];
        while(currByte != '\0'){
            ans += currByte;
            index++;
            currByte = bytes[index];
        }
        ans.append(std::to_string('\0'));
    }
    //ack
    else if(opcode == 10){
        char newBytes[2];
        newBytes[0] = bytes[2];
        newBytes[1] = bytes[3];
        short messageOpcode = bytesToShort(newBytes);
        std::string stringMessageOpcode = std::to_string(messageOpcode);
        ans.append(stringMessageOpcode);
        if(bytes.size() > 5){
            int size = bytes.size();
            for(int i=4; i<size-1;i++){
                char charByte = bytes[i];
                ans += charByte;
            }
        }
        return ans;
    }
    //error
    else if(opcode == 11){
      char newBytes[2];
      newBytes[0] = bytes[2];
      newBytes[1] = bytes[3];
      short messageOpcode = bytesToShort(newBytes);
      std::string stringMessageOpcode = std::to_string(messageOpcode);
      ans.append(stringMessageOpcode);
    }
    return ans;
}

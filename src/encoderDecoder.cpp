#include "../include/encoderDecoder.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>

encoderDecoder::encoderDecoder() {
}

std::string encoderDecoder::encode(std::string msg) const {
    std::stringstream s(msg);
    std::vector<std::string> ans;
    std::string tmp;
    std::string toSend;
    std::string zero = "\0";
    int i =0;
    while (getline(s,tmp,' ')){
        ans.push_back(tmp);
        if(ans[0]=="POST" || (ans[0]=="PM" && i==1)){
            break;
        }
        i++;

    }
    if (ans[0]=="REGISTER"){
        ans[0]="1";
        std::string username = ans[1].substr(1, ans[1].length()-2);
        ans[1] = username;
        std::string password = ans[2].substr(1,ans[2].length()-2);
        std::string birthday = ans[3].substr(1, ans[3].length()-2);
        ans[2] = zero;
        ans[3] = password;
        ans[4] = zero;
        ans[5] = birthday;
        ans[6] = zero;
    }
    else if(ans[0] == "LOGIN") {
        ans[0] = "2";
        std::string username = ans[1].substr(1, ans[1].length() - 2);
        ans[1] = username;
        std::string password = ans[2].substr(1, ans[2].length() - 2);
        std::string captcha = ans[3].substr(1, ans[3].length() - 2);
        ans[2] = zero;
        ans[3] = password;
        ans[4] = zero;
        ans[5] = captcha;
    }
    else if(ans[0] =="LOGOUT"){
        ans[0] = "3";
    }
    else if(ans[0] == "FOLLOW"){
        ans[0] = "4";
        std::string follUnfollow = ans[1].substr(1, ans[1].length() - 2);
        std::string username = ans[2].substr(1, ans[2].length() - 2);
        ans[1] = follUnfollow;
        ans[2] = username;
        ans[3] = zero;
    }
    else if(ans[0] == "POST"){
        ans[0] = "5";
        std::string content = msg.substr(6, msg.length()-2);
        ans[1] = content;
        ans[2] = zero;
    }
    else if(ans[0] == "PM"){
        std::string opcode = "6";
        std::string username = ans[1].substr(1, ans[1].length()-2);
        std::string content = msg.substr(7+username.length() , msg.length()-2);
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss<<std::put_time(&tm, "%d-%m-%Y %H:%M");
        std::string date = oss.str();
        ans[0] = opcode;
        ans[1] = username;
        ans[2] = zero;
        ans[3] = content;
        ans[4] = zero;
        ans[5] = date;
    }
    else if(ans[0] == "LOGSTAT"){
        ans[0] = "7";
    }
    else if(ans[0] == "STAT"){
        ans[0] = "8";
        ans[1] = ans[1].substr(1, ans[1].length() - 2);
    }
    else if(ans[0] == "BLOCK"){
        ans[0] = "12";
        ans[1] = ans[1].substr(1, ans[1].length() - 2);
        ans[2] = zero;
    }
    for(std::string str : ans){
        toSend.append(str);
    }
    return toSend;
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
        char type = bytes[2];
        std::string strType = std::to_string(type);
        ans.append(strType);
        int index = 3;
        char byteIndex = bytes[index];
        while(byteIndex != '\0'){
            std::string stringIndex = std::to_string(byteIndex);
            ans.append(stringIndex);
            index++;
            byteIndex=bytes[index];
        }
        ans.append(std::to_string('\0'));
        index++;
        byteIndex = bytes[index];
        while(byteIndex != '\0'){
            std::string stringIndex = std::to_string(byteIndex);
            ans.append(stringIndex);
            index++;
            byteIndex=bytes[index];
        }
        ans.append(std::to_string('\0'));
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

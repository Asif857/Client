#include "../include/encoderDecoder.h"
#include <iostream>
#include <sstream>
#include <vector>
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
        if (ans[0] == "POST" || (ans[0] == "PM" && i==1))
            break;
        i++;
    }
    if (ans[0]=="REGISTER"){
        ans[0]="1";
        std::string userName = ans[1];
        std::string pass = ans[2];
        std::string birthday = ans[3];
        ans[1]=userName;
        ans[2]=zero;
        ans[3]=pass;
        ans[4]=zero;
        ans[5]=birthday;
        ans[6]=zero;
    }
    else if (ans[0] == "LOGIN"){
        ans[0]="2";
        std::string userName = ans[1];
        std::string pass = ans[2];
        std::string captcha = ans[3];
        ans[1]=userName;
        ans[2]=zero;
        ans[3]=pass;
        ans[4]=zero;
        ans[5]=captcha;
    }
    else if (ans[0] == "LOGOUT"){
        ans[0]="3";
    }
    else if (ans[0]=="FOLLOW"){
        ans[0]="4";
        std::string follow = ans[1];
        std::string userName = ans[2];
        ans[1]=follow;
        ans[2]=userName;
        ans[3]=zero;
    }
    else if (ans[0]=="POST"){
        ans[0]="5";
        std::string content = msg.substr(5);
        ans[1]= content;
        ans[2]=zero;
    }
    else if (ans[0]=="PM") {
        ans[0] = "6";
        std::string userName = ans[1];
        std::string content=msg.substr(3+ans[1].length());
        ans[1]=userName;
        ans[2]=zero;
        ans[3]=content;
        ans[4]=zero;
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%d-%m-%Y %H:%M");
        std::string str = oss.str();
        ans[5]=str;
        ans[6]=zero;
    }
    else if (ans[0] == "LOGSTAT"){
        ans[0]="7";
    }
    else if (ans[0]=="STAT"){
        ans[0]="8";
        ans[1] = ans[1];
    }
    else if (ans[0] == "BLOCK"){
        ans[0]="12";
        ans[1]=ans[1];
        ans[2]=zero;
    }
    for (std::string str : ans){
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
            ans.append(std::to_string(currByte));
            index++;
            currByte = bytes[index];
        }
        ans.append(std::to_string('\0'));
        index++;
        currByte = bytes[index];
        while(currByte != '\0'){
            ans.append(std::to_string(currByte));
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
                ans.append(std::to_string(charByte));
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

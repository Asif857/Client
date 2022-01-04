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
        std::string userName = ans[1].substr(1,ans[1].length()-2);
        std::string pass = ans[2].substr(1,ans[1].length()-2);
        std::string birthday = ans[3].substr(1,ans[1].length()-2);
        ans[1]=userName;
        ans[2]=zero;
        ans[3]=pass;
        ans[4]=zero;
        ans[5]=birthday;
        ans[6]=zero;
    }
    else if (ans[0] == "LOGIN"){
        ans[0]="2";
        std::string userName = ans[1].substr(1,ans[1].length()-2);
        std::string pass = ans[2].substr(1,ans[1].length()-2);
        std::string captcha = ans[3].substr(1,ans[1].length()-2);
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
        std::string follow = ans[1].substr(1,ans[1].length()-2);
        std::string userName = ans[2].substr(1,ans[1].length()-2);
        ans[1]=follow;
        ans[2]=userName;
        ans[3]=zero;
    }
    else if (ans[0]=="POST"){
        ans[0]="5";
       std::string content = msg.substr(6,msg.length()-2);
       ans[1]= content;
       ans[2]=zero;
    }
    else if (ans[0]=="PM") {
        ans[0] = "6";
        std::string userName = ans[1].substr(1,ans[1].length()-2);
        std::string content=msg.substr(5+ans[1].length(),msg.length()-2);
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
        ans[1] = ans[1].substr(1,ans[1].length()-2);
    }
    else if (ans[0] == "BLOCK"){
        ans[0]="12";
        ans[1]=ans[1].substr(1,ans[1].length()-2);
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

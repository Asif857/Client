#define SPL3_BIDIPROTOCOL_H
#include <string>
#include <iostream>
#include "../include/bidiProtocol.h"
bidiProtocol::bidiProtocol(): terminate(false){}
std::string bidiProtocol::cutString(int index, std::string str){
    std::string ans;
    while(index < str.length() && str.at(index) != '\0'){
        ans += str.at(index);
        index++;
    }
    return ans;
}


void bidiProtocol::process(std::string message){
    int index;
    std::string opcode;
    if(message.at(0) == '1') {
        opcode = message.substr(0, 2);
        index = 2;
    }
    else{
        opcode = std::to_string(message.at(0));
        index = 1;
    }
    //Notification
    if(opcode == "9"){
        int notifType = message.at(1);
        index++;
        std::string postingUsername = cutString(index, message);
        index += postingUsername.size() + 1;
        std::string content = cutString(index, message);
        std::string messageType;
        if(notifType ==0){
            messageType = "PM";
        }
        else{
            messageType = "Public";
        }
        std::cout<<("NOTIFICATION <" + messageType + "> <" + postingUsername + "> <" +content +">")<<std::endl;
    }
    //ACK
    else if(opcode == "10"){
        std::string messageOpcode = std::to_string(message.at(2));
        index ++;
        if(messageOpcode == "1"){
            if(index < message.length() && message.at(index+1) =='2'){
                messageOpcode += std::to_string(message.at(index+1));
                index++;
            }
        }
        if (messageOpcode == "3"){
            terminate=true;
        }
        std::string optional;
        if(index < message.length()){
            optional = message.substr(4);
        }
        std::cout<<("ACK <" + messageOpcode + "> <" + optional +">")<<std::endl;
    }
    //ERROR
    else if(opcode == "11"){
        std::string errMsg;
        errMsg = message.substr(2);
        std::cout<<("ERROR " + errMsg)<<std::endl;
    }
}

bool bidiProtocol::shouldTerminate()const {
    return terminate;
}



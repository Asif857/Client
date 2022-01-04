#include <iostream>
#include <vector>
#include <sstream>
#include "include/encoderDecoder.h"
int main() {
    std::string opcode = "12";
    std::stringstream strOpcode(opcode);
    short shortOpcode;
    strOpcode >>shortOpcode;
}

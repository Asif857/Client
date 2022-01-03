#include <iostream>
#include <vector>
#include "include/encoderDecoder.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    const short bufsize = 1024;
    char buf[bufsize];
    encoderDecoder enc;
    std::vector<int> yop;
    enc.printstuff(yop);

}

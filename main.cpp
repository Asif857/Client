#include <iostream>
#include <vector>
#include "include/encoderDecoder.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    const short bufsize = 1024;
    char buf[bufsize];
    std::cin.getline(buf, bufsize);
    std::string line(buf);
    std::cout<<line<<std::endl;
}

#include <iostream>
#include <vector>
#include "include/encoderDecoder.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string message = "message";
    std::vector<unsigned char> v(message.begin(),message.end());
    for (int i=0;i<v.size();i++)
        std::cout<<v[i]<<std::endl;

    return 0;
}

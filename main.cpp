#include <iostream>
#include <vector>
#include <sstream>
#include "include/encoderDecoder.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::stringstream s("hello there nadav");
    std::vector<std::string> ans;
    std::string tmp;
    int i =0;
    while (getline(s,tmp,' ')){
        ans.push_back(tmp);
        std::cout<<ans[i]<<std::endl;
        i++;
    }

}

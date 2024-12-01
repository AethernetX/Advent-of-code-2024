#include "util.h"

std::vector<int> split(std::string string){
    auto p = string.find(" ");


    int a{atoi(string.substr(0, p).c_str())};
    int b{atoi(string.substr(p, string.size()).c_str())};

    std::vector<int> result{a,b};
    return result;
}
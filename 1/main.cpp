#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "util.h"

int main(){

    //parse string
    std::ifstream input{"input.txt"};

    if(!input){
        std::cerr << "Cannot read file!\n";
        return 1;
    }

    std::string strInput{};
    //parsing
    std::vector<int> left{};
    std::vector<int> right{};

    while (std::getline(input, strInput)){
        //split
        std::vector<int> result = split(strInput);
        
        //push
        left.push_back(result[0]);
        right.push_back(result[1]);

    }

    

    //part 1 solution
    ////sort arrays
    //std::sort(left.begin(), left.end());
    //std::sort(right.begin(), right.end());
    //pair
    //int result{};
    //for(int i = 0; i < left.size(); i++){
        //result += abs(left[i] - right[i]);
    //}

    ////print result
    //std::cout << result << "\n";

    //part 2 solution

    //map of frequency
    std::unordered_map<int, int> freq;

    for(int i = 0; i < right.size(); i++){
        freq[right[i]]++;
    }

    //go through all elements and refer against map
    int result{};

    for(int i = 0; i < left.size(); i++){
        result += left[i] * freq[left[i]];
    }

    std::cout << result << "\n";

    return 0;
}
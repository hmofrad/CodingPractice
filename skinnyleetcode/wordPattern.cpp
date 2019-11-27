    /*
 *  Problem: https://leetcode.com/problems/word-pattern/
 *  Compile: g++ -o wordPattern wordPattern.cpp -std=c++11 -fsanitize=address && ./wordPattern
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>

void print(std::vector<int> nums) {
    for(auto n: nums)
        printf("%d ", n);
    printf("\n");
}

//bool custom_insert(std::map<char, std::string>& hash, ) {
    
//}

bool wordPattern(std::string pattern, std::string str) {
    bool tf = true;
    std::map<char, std::string> hash;
    int m = pattern.size();
    int n = str.size();
    std::string sub_str;
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] != ' ') {
            sub_str += str[i];
        }
        
        if((str[i] == ' ') or (i == n-1)) {
            printf("%c: %s\n", pattern[j], sub_str.c_str());
            if(hash.find(pattern[j]) == hash.end()) {
                for (auto it = hash.begin(); it != hash.end(); it++) {
                    if (it->second == sub_str.c_str()) {
                        std::cout << ">>>>"  << it->first << " " << it->second << "\n";
                        tf = false;
                        break;
                    }
                }
                if(not tf) break;
                hash.insert({pattern[j], sub_str});                
            }
            else {
                if(hash[pattern[j]] != sub_str) {
                    tf = false;
                    break;
                }
            }
            if(not tf) break;
            j++;
            sub_str.clear();
        }
    }
    if(j != m) tf = false;

    for(auto& h : hash)
        std::cout << h.first << " " <<  h.second << std::endl;
    
    return(tf);
}
    #include <sstream>

int main(int argc, char **argv){
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    
    //printf("%s, %s\n", pattern.c_str(), str.c_str());
    //bool f = wordPattern(pattern, str);
    //printf("wordPattern() ? %d\n", f);
    
    /*
    std::string parsed; 
    std::string input="text to be parsed";
    std::stringstream input_stringstream(input);

    if(getline(input_stringstream, parsed, ' '))
    {
         printf("%s\n", parsed.c_str());
    }
    */

//const char delim0 = '>=+';    
   
std::string input = "Alfa=,+Bravo=,+Charlie=,+Delta";
std::string delimiter = "="; 
std::istringstream ss(input);
std::string token;
std::string::iterator it;
while(std::getline(ss, token, *(it = delimiter.begin()))) {
    while(*(++it)) ss.get();
    std::cout << token << " " << '\n';
}


    
    
    return(0);
}







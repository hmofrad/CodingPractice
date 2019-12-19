/*
 *  Cracking the coding interview: Problem 11.5: Find a string in an array of interspersed strings
 *  Compile & run: g++ -o interspersed interspersed.cpp -g -Wall -std=c++11 -fsanitize=address && ./interspersed
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
/*
int find(std::vector<std::string> strs, std::string str) {
    for(uint32_t i = 0; i < strs.size(); i++) {
        if(!str.compare(strs[i])) {
            return(i);
        }
    }
    return(0);
}
*/




int find(std::vector<std::string> strs, std::string str) {
    int left = 0;
    int right = strs.size()-1;
    int mid = strs.size()/2;
    
    while(!strs[mid].compare("")) mid++;
    
    while(true) {
        printf("[%d %s] [%d %s] [%d %s]\n", left, strs[left].c_str(), mid, strs[mid].c_str(), right, strs[right].c_str());
        int cmp = strs[mid].compare(str);
        printf("%d\n", cmp);
        if(cmp == 0) {
            return(mid);
        }
        else if(cmp > 0){
            right = mid-1;
            while((left < right) and !strs[right].compare("")) {
                right--;
            }

            while((left < right) and !strs[left].compare("")) {
                left++;
            }
            if(left > right) {
                return(-1);
            }
        }
        else{
            while((left < right) and !strs[right].compare("")) {
                right--;
            }
            left = mid+1;
            while((left < right) and !strs[left].compare("")) {
                left++;
            }
            if(left > right) {
                return(-1);
            }
        }
        mid = (left + right)/2;
    }
    
    
    return(0);
}



int main(int argc, char** argv) {
    std::vector<std::string> strs = {"at", "", "", "", "", "ball", "", "", "", "car", "", "", "dad", "", ""};
    //for(uint32_t i = 0; i < strs.size(); i++) {
    //    printf("(%d, \"%s\") ", i, strs[i].c_str());
    //}
    //printf("\n");
    
    std::string str = "ball";
    int index = find(strs, str);
    printf("strs[%d] = %s\n", index, str.c_str());
}
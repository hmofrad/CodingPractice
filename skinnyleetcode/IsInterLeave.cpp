/*
 *  Problem: IsInterLeave
 *  Compile: g++ -o IsInterLeave IsInterLeave.cpp -std=c++11 && ./IsInterLeave
 *  Execute: ./IsInterLeave
 *  (c) Mohammad Mofrad, 2018
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

bool IsInterLeave(std::string s1, std::string s2, std::string s3) {
    bool interleaved = true;
    std::vector<std::vector<int>> stat(2);

    return(interleaved);
}
int main(int argc, char** argv) {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbcbcac";
    printf("IsInterLeave? %d\n", IsInterLeave(s1, s2, s3));
    return(0);
}
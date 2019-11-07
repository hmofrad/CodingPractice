    /*
 *  Problem: https://leetcode.com/problems/nim-game/
 *  Compile: g++ -o canWinNim canWinNim.cpp -std=c++11 -fsanitize=address && ./canWinNim
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

bool canWinNim(int n) {
//    bool win = false;

    return(n%4);
}

int main(int argc, char **argv){
    int n = 4;
    bool win = canWinNim(n);
    printf("canWinNim(%d) = %d\n", n, win);
    
    return(0);
}







    /*
 *  Problem: https://leetcode.com/problems/power-of-three/submissions/
 *  Compile: g++ -o isPowerOfThree isPowerOfThree.cpp -std=c++11 && ./isPowerOfThree #-fsanitize=address 
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

/*
bool isPowerOfThree(int n) {
    if(n <= 0) 
        return 0;
    else
        return(1162261467 % n == 0);
}
*/
/*
bool isPowerOfThree(int n) {
    
    if(n <= 0) 
        return 0;
    else {
        int r = n%3;
        printf("%d\n", r);
        while((n > 1) and (r == 0)) {
            r = n%3;
            n /= 3;
            printf("%d %d\n", n, r);
        }
        return(((n == 1) and (r == 0)) == true);
        //if((n == 1) and (r == 0)) return true;
        //else return false;
    }
}
*/
bool isPowerOfThree(int n) {
    
    if(n <= 0) 
        return 0;
    else {

        while(n%3 == 0) {
            n = n/3;
        }
        return(n == 1);
        //if((n == 1) and (r == 0)) return true;
        //else return false;
    }
}


int main(int argc, char **argv){
    int n = 27;
    int p = isPowerOfThree(n);
    printf("isPowerOfThree(%d)=%d\n", n, p);

    return(0);
}







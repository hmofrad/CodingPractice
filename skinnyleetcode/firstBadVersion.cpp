    /*
 *  Problem: https://leetcode.com/problems/first-bad-version/submissions/
 *  Compile: g++ -o firstBadVersion firstBadVersion.cpp -std=c++11 && ./firstBadVersion
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


bool isBadVersion(int version) {
    return(version == 9);
}

/*
int firstBadVersion(int n) {
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        //printf("%d %d\n", i, isBadVersion(i));
        if(isBadVersion(i)) {
            ret = i;
            break;
        }
    }
    return ret;
}
*/
/*
long long l = 1, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(isBadVersion(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r + 1;
*/
int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    int mid = n/2;
    while(l <= r) {
        mid = l + (r - l)/2;
        printf("%d %d %d\n", l, r, mid);
        if(isBadVersion(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return(r+1);
}


    
int main(int argc, char **argv){
    int n = 11;
    int bad = firstBadVersion(n);
    printf("firstBadVersion(%d)=%d\n", n, bad);
    
    return(0);
}







/*
 *  URL: https://leetcode.com/problems/majority-element/
 *  Compile & Execute: g++ -o majorityElement majorityElement.cpp -std=c++11 && ./majorityElement
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class Solution {
public:
    static int majorityElement(std::vector<int>& nums) {
        int n = nums.size();
        int nm = floor(nums.size()/2) + 1;
        std::vector<int> visited; 
        int me = 0;
        int c = 0;
        for(int i = 0; i < nm; i++) {
            me = nums[i];
            c = 0;
            printf("%d: %d %d\n", i, me ,c);
            //int m = visited.size();
            //for(int j = 0; j < m; j++) {
              //  if(visited[j] == me) {
                //    continue;
                //}
            //}
            bool tf = (std::find(visited.begin(), visited.end(), me) == visited.end());
            if(tf) {

            printf("11.%d: %d %d\n", i, me ,c); 
            for(int j = 0; j < n/2; j++) {
                if((nums[j] == nums[n-j-1]) and (nums[j] == me)) {
                        c += 2;
                }
                else if((nums[j] == me) or (nums[n-j-1] == me)) {
                        c++;
                }
            //for(int j = 0; j < n; j++) {
              //  if(nums[j] == me)
                //    c ++;
                if(c >= nm)
                    break;
            }
            //printf("%d: %d %d\n", i, me ,c); 
            if(n%2) {
                if(nums[(n/2)] == me)
                    c++;
            }
            //printf("%d: %d %d\n", i, me ,c);    
            if(c >= nm)
                break;
            visited.push_back(me);
            }
        }
        return(me);
    }
};

int main(int argc, char **argv) {
    //std::vector<int> n = {1};
    std::vector<int> n = {10,9,9,9,10};
    int out = Solution::majorityElement(n);
    printf("<%d>\n", out);
    return(0);
}    

/*
 *  URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *  Compile & Execute: g++ -o twoSum twoSum.cpp -std=c++11 && ./twoSum
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> res(2);
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int s = numbers[i] + numbers[j];
            if(s == target) {
                res[0] = i+1;
                res[1] = j+1;
                break;
            }
            else if(s > target) {
                j--;
            }
            else {
                i++;                
            }
            printf("%d %d %d\n", i, j, numbers.size());
        }
        return(res);
    }
};

int main(int argc, char **argv) {
    std::vector<int> numbers = {2,7,11,15}; 
    int target = 9;
    std::vector<int> vec = Solution::twoSum(numbers, target);
    printf("[%d %d]\n", vec[0], vec[1]);
    return(0);
}    

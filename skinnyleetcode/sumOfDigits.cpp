/*
 *  https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/submissions/
 *  Compile & run: g++ -o numTilePossibilities numTilePossibilities.cpp -g -Wall -std=c++11 -fsanitize=address  && ./numTilePossibilities
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min = *std::min_element(A.begin(), A.end());
        int d = 0;
        while(min){
            int r = min %10;
            d += r;
            min /= 10;
        }
        //printf("%d\n", d);
        return(not(d%2));
    }
};
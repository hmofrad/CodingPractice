/*
 *  Problem: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int countDigits(int num) {
        int c = 0;
        while(num){
            num /= 10;
            c++;
        }
        return(c);
    }
    int findNumbers(vector<int>& nums) {
        int m = 0;
        for(auto n: nums) {
            if(not(countDigits(n) % 2)) m++;
        }
        return(m);
    }
};
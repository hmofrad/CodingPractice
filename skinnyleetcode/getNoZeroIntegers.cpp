/*
 *  https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool check(int a) {
        while(a) {
            int r = a%10;
            if(r==0) return false;
            a /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int left=1;
        int right=n-1;
        while(true) {
            bool l = check(left);
            bool r = check(right);
            if(l and r) return std::vector<int>({left,right});
            else {left++; right--;}
        }
        return std::vector<int>({-1,-1});
    }
};
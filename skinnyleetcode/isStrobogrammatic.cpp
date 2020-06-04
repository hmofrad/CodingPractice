/*
 *  https://leetcode.com/problems/strobogrammatic-number/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isStrobogrammatic(string num) {
        std::unordered_map<char, char> digits = {{'0','0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int left = 0;
        int right = num.length()-1;
        while(left<=right) {
            char l = num[left];
            char r = num[right];
            if(digits.count(l)==0 or digits.count(r)==0) return false;
            if(l != digits[r]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool isStrobogrammatic1(string num) {
        std::unordered_map<char, char> digits = {{'0','0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        std::string num1;
        for(int i = num.length()-1; i>=0; i--) {
            char c = num[i];
            if(digits.count(c)==0) return false;
            else num1.push_back(digits[c]);
        }
        return num == num1;
    }
};
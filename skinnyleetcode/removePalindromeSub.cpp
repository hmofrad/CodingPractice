/*
 *  https://leetcode.com/problems/remove-palindromic-subsequences/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int removePalindromeSub(string s) {
        std::string t = s;
        std::reverse(t.begin(), t.end());
        return s.empty() ? 0 : t == s ? 1 : 2;
    }
};
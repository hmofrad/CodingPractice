/*
 *  Problem: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minSteps(string s, string t) {
        std::vector<int> alpha(26);
        int len = s.length();
        for(int i = 0; i < len; i++) {
            alpha[s[i]-'a']++;
        }
        
        for(int i = 0; i < len; i++) {
            if(alpha[t[i]-'a']>0)
                alpha[t[i]-'a']--;
        }
        
        int d = 0;
        for(int i = 0; i < 26; i++) {
            d += alpha[i];
        }
        
        return(d);
    }
};
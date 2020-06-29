/*
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    int func(std::string& s, int k, int u) {
        std::vector<int> counts(26);
        int nu = 0, nk = 0;
        int i = 0, j = 0;
        int longest = 0;
        int length = s.length();
        while(i < length) {
            if(nu<=u) {
                int index = s[i++]-'a';
                if(counts[index]++==0) nu++;
                if(counts[index]==k) nk++;
            }
            else {
                int index = s[j++]-'a';
                if(counts[index]-- == k) nk--;
                if(counts[index] == 0) nu--;
            }
            if(nu == u and nu == nk) longest = max(longest, i-j);
        }
        return longest;
    }
    
    int longestSubstring(string s, int k) {
        int longest = 0;
        for(int u = 1; u <= 26; u++) { longest = max(longest, func(s, k, u)); }
        
        return longest;
    }
};
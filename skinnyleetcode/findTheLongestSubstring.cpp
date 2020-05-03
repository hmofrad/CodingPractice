/*
*	https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    const int vowels = 0 | (1<<('a'-'a')) | (1<<('e'-'a')) | (1<<('i'-'a')) | (1<<('o'-'a')) | (1<<('u'-'a'));
    
    
    int findTheLongestSubstring(string s) {
        int len = s.length();
        std::unordered_map<int ,int> m{{0,-1}};
        int maxLen=0;
        int mask = 0;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            mask ^= (1<<(c-'a'))&vowels;
            if(m.count(mask)) maxLen=max(maxLen, i-m[mask]);
            else m[mask]=i;
        }
        
        
        for(int i = 31; i >= 0; i--) {
            int mask=1<<i;
            int b = mask&vowels;
            if(b) printf("1");
            else printf("0");
        }
        printf("\n");
        
        return maxLen;
    }
};


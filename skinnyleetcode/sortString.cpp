/*
 *  Problem: https://leetcode.com/problems/increasing-decreasing-string/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    string sortString(string s) {
        std::vector<int> words(26);
        for(auto c: s) {
            words[c-'a']++;
        }
        
        int len = s.length();
        int k = 0;
        std::string out;
        while(k < len) {
           // printf("k=%d\n", k);
            for(int i = 0; i < 26; i++) {
                if(words[i]) {
                    out += (char)('a' + i);
                    words[i]--;
                    k++;
                }
            }
            
            for(int i = 25; i >= 0; i--) {
                if(words[i]) {
                    out += (char)('a' + i);
                    words[i]--;
                    k++;
                }
            }

        }
        return(out);
    }
};
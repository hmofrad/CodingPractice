/*
 *	https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    int numberOfSubstrings2(string s) {
        std::vector<int> counts(3);
        int k = 0;
        int c = 0;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            int j = s[i]-'a';
            counts[j]++;
            while(counts[0] and counts[1] and counts[2]) counts[s[k++]-'a']--;
            c += k;
        }
        return c;
    }
    int numberOfSubstrings1(string s) {
        int len = s.size();
        int j=0;
        int nsubstrings = 0;
        for(int i = 0; i <= len-3; i++) {
            std::unordered_map<char, int> counts;
            for(int j = i; j < len; j++) {
                char c = s[j];
                counts[c]++;
                if(counts.size()==3) {
                    nsubstrings++;
                }
            }
        }
        return nsubstrings;
    }
};
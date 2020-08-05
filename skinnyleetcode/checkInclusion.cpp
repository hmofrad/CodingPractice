/*
 * https://leetcode.com/problems/permutation-in-string/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.empty() and s2.empty()) { return true; }
        else if(s1.empty() and not s2.empty()) { return true; }
        else if(not s1.empty() and s2.empty()) { return false; }
        int len1 = s1.length();
        std::unordered_map<char, int> map1;
        for(char c: s1) { map1[c]++; }
        int len2 = s2.length();
        std::unordered_map<char, int> map2;
        for(int i = 0; i < len2; i++) {
            char c = s2[i];
            map2[c]++;
            if(i>=len1) {
                char x = s2[i-len1];
                map2[x]--;
                if(map2[x] == 0) { map2.erase(x); }
            }
            if(map1 == map2) { return true; }
        }
        return false;
    }
};
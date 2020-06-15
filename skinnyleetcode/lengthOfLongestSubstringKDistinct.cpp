/*
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty()) return 0;
        std::unordered_map<char, int> map;
        int i = 0, j = 0;
        int len = s.length();
        int ans = 0;
        while(i<len) {
            map[s[i]]++;
            while(map.size()>k) {
                map[s[j]]--;
                if(map[s[j]]==0) map.erase(s[j]);
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};
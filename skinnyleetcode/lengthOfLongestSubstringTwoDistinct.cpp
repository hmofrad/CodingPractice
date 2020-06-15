/*
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty()) return 0;
        std::unordered_map<char, int> map;
        int len = s.length();
        int i = 0, j =0;
        int ans = 0;
        while(i<len) {
            map[s[i]]++;
            while(map.size()>2) {
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
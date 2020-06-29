/*
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
        int lengthOfLongestSubstring(string s) {
        //s="abba";
        std::unordered_map<char, int> map;
        int longest = 0;
        int count=0;
        for(int i = 0, j = 0; i < s.length(); i++) {
            char c = s[i];
            if(map.count(c)) {
                j=max(j, map[c]+1);
            }
            //printf("%d %d %c\n", i, j, c);
            longest = max(longest, i-j+1);
            map[c]=i;
        }

        return longest;
    }
    bool unique(std::string s, int start, int end) {
        std::unordered_set<char> set;
        for(int i = start; i < end; i++) {
            char c = s[i];
            if(not set.insert(c).second) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring2(string s) {
        int mx = 0;
        int length = s.length();
        for(int i = 0; i < length; i++) {
            for(int j = i+1; j <= length; j++) {
                if(unique(s, i, j)) mx = max(mx, j-i);
            }
        }
        return mx;
    }
    int lengthOfLongestSubstring1(string s) {
        std::set<char> set;
        int j = 0;
        int longest = 0;
        int count=0;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(set.count(c)) {
                longest = max(longest, count);
                while(s[j]!=c){ set.erase(s[j]); j++; count--;}
                j++;
            }
            else {set.insert(c); count++;}
        }
        longest = max(count, longest);
        return longest;
    }
};
/*
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.empty() or p.empty()) { return std::vector<int>(); }
        std::unordered_map<char, int> map;
        for(char c: p) { map[c]++; }
        int len = s.length();
        int size = p.length();
        std::vector<int> ans;
        int j = 0;
        std::unordered_map<char, int> temp;
        int sz = 0;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            temp[c]++;
            if(i>=size) {
                char x = s[i-size];
                temp[x]--;
                if(temp[x] == 0) { temp.erase(x); }
            }
            if(temp == map) { ans.push_back(i-size+1); }
        }
        return ans;
    }
    vector<int> findAnagrams0(string s, string p) {
        if(s.empty() or p.empty()) { return std::vector<int>(); }
        

        std::unordered_map<char, int> map;
        for(char c: p) { map[c]++; }
        int len = s.length();
        int size = p.length();
        std::vector<int> ans;
        int j = 0;
        std::unordered_map<char, int> temp;
        int sz = 0;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(map.count(c)) {
                temp[c]++;
                sz++;
                if(temp[c]>map[c]) {
                    while(temp[c]>map[c]) {
                        char x = s[j++];
                        temp[x]--;
                        if(temp[x]==0) { temp.erase(x); }
                        sz--;
                    }  
                }
                if(sz == size) {
                    ans.push_back(j);
                    char x = s[j++];
                    temp[x]--;
                    if(temp[x]==0) { temp.erase(x); }
                    sz--;
                }             
            }
            else {
                temp.clear();
                sz = 0;
                j = i+1;
            }

        }
        return ans;
    }
};
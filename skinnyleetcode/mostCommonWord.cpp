/*
 * https://leetcode.com/problems/most-common-word/solution/ 
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::string parse(std::string& s, int& i) {
        int len = s.length();
        if(i==len) { return std::string(); }
        while(i<len and not ((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))) { i++; }
        int j = i;
        while(j<len and ((s[j]>='a' and s[j]<='z') or (s[j]>='A' and s[j]<='Z'))) { 
            if(s[j]>='A' and s[j]<='Z') { s[j] += (-'A'+'a'); }
            j++; 
        }
        std::string t = s.substr(i, j-i);
        i=j;
        return t;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        std::unordered_map<std::string, int> map;
        
        int i = 0;
        while(true) {
            std::string token = parse(paragraph, i);
            //printf("[%s]\n", token.c_str());
            if(token.empty()) { break; }
            map[token]++;
        }
        
        std::vector<std::pair<std::string, int>> pairs;
        for(auto m: map) { pairs.push_back({m.first, m.second}); }
        
        std::sort(pairs.begin(), pairs.end(), [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
            return a.second < b.second;
        });
        
        std::unordered_set<std::string> set(banned.begin(), banned.end());
        
        while(not pairs.empty()) {
            if(set.count(pairs.back().first)) { pairs.pop_back(); }
            else { return pairs.back().first; }
        }
        
        
        return std::string();
    }
};
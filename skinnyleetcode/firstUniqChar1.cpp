/*
 * https://leetcode.com/problems/first-unique-character-in-a-string/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<std::pair<int, int>> map(26);
        int len = s.length();
        for(int i = 0; i < len; i++) {
            int j = s[i]-'a';
            map[j].first++; 
            map[j].second = i;
        }
        
        int first = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(map[i].first == 1) { first = min(first, map[i].second); }
        }
        return first != INT_MAX ? first : -1;
    }
    
    
    int firstUniqChar2(string s) {
        //if(s.empty()) return -1;
        //s = "";
        std::unordered_map<char, int> map;
        std::unordered_set<char> set;
        int size = s.length();
        for(int i = 0; i < size; i++) {
            char c = s[i]; 
            if(set.count(c)) {
                if(map.count(c)) map.erase(c);
            }
            else {
                set.insert(c);
                map[c]=i;
            }
           // printf("%d %c %d %c\n", i, c, index, value);
        }
        return -1;
        //return map.empty() ? -1 : *map.begin()->second;
    }
    
    int firstUniqChar(string s) {
            std::vector<int> alpha(27);
    for(auto c: s) {
        alpha[c-'a']++;
    }
    
    //for(auto a: alpha) {
    //    printf("%d ", a);
    //}
    //printf("\n");
    
    
    for(uint32_t i = 0; i < s.size(); i++) {
        auto c = s[i];
        if(alpha[c-'a'] == 1)
            return(i);
    }
    
    return(-1); 
    }
};
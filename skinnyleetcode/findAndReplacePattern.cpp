/*
 *  https://leetcode.com/problems/find-and-replace-pattern/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool compare1(std::string word, std::string pattern) {
        std::unordered_map<char, int> w;
        std::unordered_map<char, int> p;
        int m = word.length();
        for(int i = 0; i < m; i++) {
            w[word[i]]++;
            p[pattern[i]]++;
        }
        int n = 0;
        std::unordered_map<int, std::vector<bool>> p2c;
        for(auto pat: p) {
            p2c[pat.second].push_back(true);
            n += pat.second;
        }
        
        for(auto wo: w) {
            auto t = p2c.find(wo.second);
            if(t != p2c.end()) {
                if(not t->second.empty()) {
                    n -= wo.second;                    
                    t->second.pop_back();
                }
            }
        }
        return(n==0);
    }
    
    bool compare(std::string word, std::string pattern) {
        std::unordered_map<char, char> map1;
        std::unordered_map<char, char> map2;
        int m = pattern.size();
        for(int i = 0 ; i < m; i++) {
            char w = word[i];
            char p = pattern[i];
            
            if(map1.find(w) == map1.end()) {
                map1[w] = p;
            }
            
            if(map2.find(p) == map2.end()) {
                map2[p] = w;
            }
            if((map1.find(w)->second != p) or (map2.find(p)->second != w)) return(false);
        }
        return(true);
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        std::vector<string> ret;
        for(auto word: words) {
            if(compare(word, pattern)) ret.push_back(word);
        }
        return(ret);
    }
};
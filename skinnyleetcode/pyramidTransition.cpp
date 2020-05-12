/*
 *	https://leetcode.com/problems/pyramid-transition-matrix/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    
    
    bool dfs(std::unordered_map<std::string, std::vector<char>>& patterns, std::string bottom, int index, std::string next) {
        int len = bottom.length();
        if(len == 1) return true;
        if(index == len-1) return dfs(patterns, next, 0, std::string());
        std::string k = bottom.substr(index, 2);
        for(char c: patterns[k]) {
            if(dfs(patterns, bottom, index+1, next+c)) return true;
        }
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        std::unordered_map<std::string, std::vector<char>> patterns;
        for(std::string& a: allowed) {
            std::string key = a.substr(0,2);
            char value = a.back();
            patterns[key].push_back(value);
        }
        
        return dfs(patterns, bottom, 0, std::string());
    }
};
/*
 * https://leetcode.com/problems/decode-ways/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    std::unordered_map<int, int> map;
    int dfs(std::string& s, int index) {
        int len = s.length();
        if(index == len) { return 1; }
        if(s[index] == '0') { return 0; }
        if(index == len-1) { return 1; }
        if(map.count(index)) { return map[index]; }
        
        int ans = dfs(s, index+1);
        if(stoi(s.substr(index, 2)) <= 26 ) { ans += dfs(s, index+2); }
        map[index] = ans;
        return ans;
    }
    int numDecodings(string s) {
        if(s.empty()) { return 0; }
        return dfs(s, 0);
    }
};


class Solution0 {
public:
    int count = 0;
    void dfs(std::string& s, int start, int length, std::vector<std::string> temp, std::unordered_map<std::string, char>& map, std::vector<std::vector<std::string>>& ans) {
        int len = s.length();
        if(start+length == len) {
            std::string t = s.substr(start, length);
            if(map.count(t)) { 
                temp.push_back(t);
                //ans.insert(temp); 
                ans.push_back(temp); 
            }
            return;
        }
        
        std::string t = s.substr(start, length);        
        if(map.count(t)) { 
            temp.push_back(t);
            dfs(s, start+length, 0, temp, map, ans); 
            temp.pop_back();
        }
        dfs(s, start, length+1, temp, map, ans);
    }
    int numDecodings(string s) {
        if(s.empty()) { return 0; }
        //std::set<std::vector<std::string>> ans;
        std::vector<std::vector<std::string>> ans;
        std::unordered_map<std::string, char> map;
        for(char c = 'A'; c <= 'Z'; c++) {
            std::string key = to_string(c-'A'+1);
            map[key]=c;
        }
        
        dfs(s, 0, 1, std::vector<std::string>(), map, ans);
        
        //for(auto a: ans) { 
        //    for(auto as: a) {  printf("%s, ", as.c_str()); }
        //    printf("\n");
        //}
        
        return ans.size();
    }
};
/*
 * https://leetcode.com/problems/accounts-merge/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void dfs(std::unordered_map<std::string, std::unordered_set<std::string>>& map, std::unordered_set<std::string>& visited, std::string src, std::vector<std::string>& temp) {
        if(visited.insert(src).second == false) { return; }
        temp.push_back(src);
        std::unordered_set<std::string>& set = map[src];
        for(std::string s: set) { dfs(map, visited, s, temp); }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map<std::string, std::string> names;
        int naccounts = accounts.size();
        for(int i = 0; i < naccounts; i++) {
            int nemails = accounts[i].size();
            std::string name = accounts[i][0];
            for(int j = 1; j < nemails; j++) { names[accounts[i][j]] = name; }
        }
        
        std::unordered_map<std::string, std::unordered_set<std::string>> map;
        for(int i = 0; i < naccounts; i++) {
            int nemails = accounts[i].size();
            for(int j = 1; j < nemails; j++) { 
                map[accounts[i][1]].insert(accounts[i][j]); 
                map[accounts[i][j]].insert(accounts[i][1]); 
            }
        }
        
        std::unordered_set<std::string> visited;
        vector<vector<string>> ans;
        for(auto m: map) {
            std::vector<std::string> temp;
            std::string key = m.first;
            if(visited.count(key)) { continue; }
            temp.push_back(names[key]);
            if(not m.second.empty()) { dfs(map, visited, key, temp); }
            if(temp.size()>2) { std::sort(temp.begin()+1, temp.end()); }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
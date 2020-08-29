/*
 * https://leetcode.com/problems/reconstruct-itinerary/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::string> path;
    void dfs(std::unordered_map<std::string, std::vector<std::string>>& map, std::string src) {
        while(not map[src].empty()) {
            std::string dst = map[src].back();
            map[src].pop_back();
            dfs(map, dst);
        }
        path.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(std::vector<std::string>& ticket: tickets) {
            std::string src = ticket[0];
            std::string dst = ticket[1];
            map[src].push_back(dst);
        }
        
        for(auto& m: map) {
            std::string key = m.first;
            std::vector<std::string>& values = m.second;
            std::sort(values.begin(), values.end(), std::greater<std::string>());
        }
        
        dfs(map, "JFK");
        std::reverse(path.begin(), path.end());
        return path;
    }
};































class Solution3 {
public:
    std::unordered_map<std::string, std::multiset<std::string>> map;
    std::vector<std::string> path;
    void visit(std::string src) {
        while(not map[src].empty()) {
            std::string dst = *map[src].begin();
            map[src].erase(map[src].begin());
            visit(dst);
        }
        path.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(std::vector<std::string>& ticket: tickets) {
            std::string& src = ticket[0];
            std::string& dst = ticket[1];
            map[src].insert(dst);
        }
        visit("JFK");
        std::reverse(path.begin(), path.end());
        return path;
    }
    
};
class Solution0 {
public:
    
    std::vector<std::string> ans;
    void dfs(std::unordered_map<std::string, std::vector<std::string>> map, int size, std::string src, std::vector<std::string> path, std::set<std::pair<std::string, std::string>> visited) {
        printf("%s %d\n", src.c_str(), path.size());
        if(path.size() == size) { path.push_back(src); ans = path; return;}
        if(map.count(src) == 0) { return;}
        
        std::vector<std::string>& destinations = map[src];
        for(std::string& dst: destinations) {
            //if(visited.insert({src, dst}).second == false) continue;
            
            path.push_back(src);
            dfs(map, size, dst, path, visited);
            visited.erase({src, dst});
        }
    }
    vector<string> findItinerary0(vector<vector<string>>& tickets) {
        //tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
        tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
        std::sort(tickets.begin(), tickets.end(), [](std::vector<std::string>& a, std::vector<std::string>& b) { return a[1] > b[1]; });
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(std::vector<std::string>& ticket: tickets) {
            std::string& src = ticket[0];
            std::string& dst = ticket[1];
            map[src].push_back(dst);
        }
        
        for(auto m: map) {
            std::string key = m.first;
            auto values = m.second;
            printf("%s ", key.c_str());
            for(auto v: values) printf("%s ", v.c_str()); printf("\n");
        }
        
        int size = tickets.size();
        std::vector<std::string> path;
        //path.push_back("JFK");
        std::set<std::pair<std::string, std::string>> visited;
        dfs(map, size, "JFK", std::vector<std::string>(), visited);
        /*
        while(not map.empty()) {
            std::string key = ans.back();
            std::vector<std::string>& values = map[key];
            ans.push_back(values.back());
            values.pop_back();
            if(values.empty()) { map.erase(key); }
        }
        */
        return ans;
    }
};
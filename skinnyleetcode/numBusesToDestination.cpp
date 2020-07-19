/*
 * https://leetcode.com/problems/bus-routes/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T) { return 0; }
        
        std::unordered_set<int> visited;
        std::queue<int> queue; queue.push(S);
        std::unordered_map<int, std::vector<int>> map;
        int cost = 0;
        
        
        for(int i = 0; i < routes.size(); i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                map[routes[i][j]].push_back(i);
            }
        }
        
        while(not queue.empty()) {
            int s = queue.size();
            cost++;
            while(s) {
                int front = queue.front(); queue.pop();
                std::vector<int>& buses = map[front];
                for(int& bus: buses) {
                    if(visited.insert(bus).second) {
                        for(int j = 0; j < routes[bus].size(); j++) {
                            if(routes[bus][j]==T) { return cost; }
                            else { queue.push(routes[bus][j]); }
                        }
                    } 
                }
                s--;
            }
        }
        
        
        return -1;
    }
};

class Solution0 {
public:
    
    int dfs(std::vector<std::unordered_map<int, int>>& map0,
            std::unordered_map<int, std::unordered_set<int>>& map1,
            std::unordered_set<int>& visited,
            int route, int source, int target, int cost) {
        if(source == target) { return cost; }
        
        if(visited.insert(source).second == false) { return -1; }    
        
        
        visited.erase(source);
        
        
        return 0;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int nroutes = routes.size();
        int nstations = nroutes ? routes[0].size() : 0;
        std::vector<std::unordered_map<int, int>> map0;
        
        for(int i = 0; i < nroutes; i++) {
            std::unordered_map<int,int> map;
            for(int j = 0; j < nstations; j++) {
                map[routes[i][j]] = routes[i][(j+1)%nstations];
            }
            map0.push_back(map);
        }
        
        std::unordered_map<int, std::unordered_set<int>> map1;

        for(int i = 0; i < nroutes; i++) {
            std::vector<int>& route = routes[i];
            for(int& station: route) {
                map1[station].insert(i);
            }
        }
        
        std::unordered_set<int> visited;
        
        return dfs(map0, map1, visited, 0, S, T, 0);
    }
};
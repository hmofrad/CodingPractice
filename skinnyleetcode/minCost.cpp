/*
 *	https://leetcode.com/problems/paint-house/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        for(int i = costs.size()-2; i>= 0; i--) {
            costs[i][0] += min(costs[i+1][1], costs[i+1][2]);
            costs[i][1] += min(costs[i+1][0], costs[i+1][2]);
            costs[i][2] += min(costs[i+1][0], costs[i+1][1]);
        }
        return min({costs[0][0], costs[0][1], costs[0][2]});
    }
    
    
    std::unordered_map<std::string,int> mem;
    int dfs(vector<vector<int>>& costs, int index, int color) {
        std::string key = to_string(index) + "+" + to_string(color);
        if(mem.count(key)) return mem[key];   
        int this_cost = costs[index][color];
         if(index < costs.size()-1) {
            if(color==0) {
                this_cost += min(dfs(costs, index+1, 1), dfs(costs, index+1, 2));
            }
            else if(color==1) {
                this_cost += min(dfs(costs, index+1, 0), dfs(costs, index+1, 2));
            }
            else if(color==2) {
                this_cost += min(dfs(costs, index+1, 0), dfs(costs, index+1, 1));
            }
        }
        mem[key] = this_cost;
        return this_cost;
    }
    int minCost2(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        return min({dfs(costs, 0, 0), dfs(costs, 0, 1), dfs(costs, 0, 2)});
    }
    
    int dfs1(vector<vector<int>>& costs, int index, int color, int cost) {
        if(index==costs.size()) return cost;
        int gain = costs[index][color];
        int this_cost = 0;
        if(index < costs.size()) {
            if(color==0) {
                this_cost = min(dfs1(costs, index+1, 1, cost+gain), dfs1(costs, index+1, 2, cost+gain));
            }
            else if(color==1) {
                this_cost = min(dfs1(costs, index+1, 0, cost+gain), dfs1(costs, index+1, 2, cost+gain));
            }
            else if(color==2) {
                this_cost = min(dfs1(costs, index+1, 0, cost+gain), dfs1(costs, index+1, 1, cost+gain));
            }
        }
        
        return this_cost;
    }
    
    int minCost1(vector<vector<int>>& costs) {
        return min({dfs1(costs, 0, 0, 0), dfs1(costs, 0, 1, 0), dfs1(costs, 0, 2, 0)});
    }
};
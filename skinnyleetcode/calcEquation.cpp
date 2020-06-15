/*
 * https://leetcode.com/problems/read-n-characters-given-read4/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    double dfs(std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& graph, 
               std::string src, std::string dst, std::set<std::string>& visited, double product) {
        if(graph.count(src) == 0 or graph.count(dst) == 0) return -1;
        if(not visited.insert(src).second) return -1;
        if(src==dst and product==0) return 1;
        if(src==dst) return product;
        
        double ans = -1;
        std::vector<std::pair<std::string, double>>& row = graph[src];
        for(std::pair<std::string, double>& col: row) {
            std::string src0 = col.first;
            double cost = col.second;
            if(visited.count(src0)==0) {
                double product0 = product==0 ? cost : product*cost;
                double t = dfs(graph, src0, dst, visited, product0); 
                if(t!=-1) {ans=t; break;}
            }
        }
        visited.erase(src);
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
        int size = equations.size();
        for(int i = 0; i < size; i++) {
            std::vector<std::string>& equation = equations[i];
            std::string u = equation[0];
            std::string v = equation[1];
            graph[u].push_back({v,values[i]});
            graph[v].push_back({u,(double) 1/values[i]});
            graph[u].push_back({u,1});
            graph[v].push_back({v,1});
        }
        
        std::vector<double> ans;
        for(std::vector<std::string> query: queries) {
            std::string u = query[0];
            std::string v = query[1];
            std::set<std::string> visited;
            ans.push_back(dfs(graph, u, v, visited, 0));
           // break;
        }
        return ans;
    }
};

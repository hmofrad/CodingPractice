/*
 *  https://leetcode.com/problems/all-paths-from-source-to-target/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    std::vector<std::vector<int>> out;
    
    void dfs(int vertex, std::vector<int> visited, std::vector<std::vector<int>>& graph) {
        int m = graph.size();
        if(vertex == m-1) {
            out.push_back(visited);
        }
        else {
            for(int j = 0; j < graph[vertex].size(); j++) {
                visited.push_back(graph[vertex][j]);
                dfs(graph[vertex][j], visited, graph);
                visited.erase(visited.end()-1);
            }
        }
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<int> start;
        start.push_back(0);
        dfs(0, start, graph);
        return(out);        
    }
};

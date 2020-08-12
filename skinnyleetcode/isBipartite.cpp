/*
 * https://leetcode.com/problems/is-graph-bipartite/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    // 0 not colored, 1 red, -1 blue
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        std::vector<int> colors(size);
        for(int i = 0; i < size; i++) {
            if(colors[i]==0 and not valid_color(graph, colors, 1, i)) { return false; }
        }
        return true;
    }
    bool valid_color(vector<vector<int>>& graph, std::vector<int>& colors, int color, int src) {
        if(colors[src] != 0) { return colors[src] == color; }
        colors[src] = color;
        for(int dst: graph[src]) {
            if(not valid_color(graph, colors, -color, dst)) { return false; }
        }
        return true;
    }
};
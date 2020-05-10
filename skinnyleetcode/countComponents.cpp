/*
 *	https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int union_find(std::vector<int>& u, int a) {
        return u[a] == -1 ? a : union_find(u, u[a]);
    }
    void union_merge(std::vector<int>& u, int a, int b) {
        int u_a = union_find(u, a);
        int u_b = union_find(u, b);
        if(u_a!=u_b) u[u_a]=u_b;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<int> u(n, -1);
        for(std::vector<int>& edge: edges) {
            int u_u = union_find(u, edge[0]);
            int u_v = union_find(u, edge[1]);
            union_merge(u, u_u, u_v);
        }
        int nc = 0;
        for(int& uu: u) {nc += uu==-1 ? 1:0;}
        return nc;
    }
};
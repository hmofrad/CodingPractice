/*
 *	https://leetcode.com/problems/redundant-connection/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    int union_find(std::vector<int>& unions, int u) {
        return unions[u] == -1 ? u : union_find(unions, unions[u]);
    }
    bool union_merge(std::vector<int>& unions, int u, int v) {
        int p_u = union_find(unions, u);
        int p_v = union_find(unions, v);
        bool b = true;
        if(p_u != p_v) {unions[p_u] = p_v; b=false;}
        return b;
    }
    /*
    bool union_check(std::vector<int>& unions, ) {
        union_check()
        int c = 0;
        for(int i = 1; i < unions.size(); i++) {
            
        }
    }
    */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nnodes = 0;
        for(std::vector<int>& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            nnodes = (u>nnodes) ? u : nnodes;
            nnodes = (v>nnodes) ? v : nnodes;
        }
        //printf("%d\n", nnodes);
        std::vector<int> e(2);
        std::vector<int> unions(nnodes+1, -1);
        for(std::vector<int>& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            //printf("%d %d\n", u, v);
            int u_u = union_find(unions, u);
            int u_v = union_find(unions, v);
            //printf("%d %d\n", u_u, u_v);
            bool b = union_merge(unions, u_u, u_v);
            //printf("%d %d %d %d %d\n", u, u_u, v, u_v, b);
            if(b) e=edge;
            //for(int un: unions) printf("%d ", un); printf("\n");
        }
        return e;
    }
};
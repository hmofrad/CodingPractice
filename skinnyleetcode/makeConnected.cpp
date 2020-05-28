/*
 *	https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int union_find(std::vector<int>& unions, int u) {
        return unions[u]==-1 ? u : union_find(unions, unions[u]);
    }
    bool union_merge(std::vector<int>& unions, int u, int v) {
        int uu = union_find(unions, u);
        int vv = union_find(unions, v);
        if(uu!=vv) {unions[u]=v; return true;}
        return false;
    }
    int makeConnected1(int n, vector<vector<int>>& connections) {
        //test(n, connections);
        int m = connections.size();
        if(m+1<n) return -1;
        std::vector<int> unions(n,-1);
        for(std::vector<int>& conn: connections) {
            int e0 = conn[0];
            int e1 = conn[1];
            int u = union_find(unions, e0);
            int v = union_find(unions, e1);
            if(union_merge(unions, u, v)) n--;
        }
        //printf("%d\n", n);
        return n-1;
    }
    
    
    
    void test(int& n, vector<vector<int>>& connections) {
        n=100;
        connections={{17,51},{33,83},{53,62},{25,34},{35,90},{29,41},{14,53},{40,84},{41,64},{13,68},{44,85},{57,58},{50,74},{20,69},{15,62},{25,88},{4,56},{37,39},{30,62},{69,79},{33,85},{24,83},{35,77},{2,73},{6,28},{46,98},{11,82},{29,72},{67,71},{12,49},{42,56},{56,65},{40,70},{24,64},{29,51},{20,27},{45,88},{58,92},{60,99},{33,46},{19,69},{33,89},{54,82},{16,50},{35,73},{19,45},{19,72},{1,79},{27,80},{22,41},{52,61},{50,85},{27,45},{4,84},{11,96},{0,99},{29,94},{9,19},{66,99},{20,39},{16,85},{12,27},{16,67},{61,80},{67,83},{16,17},{24,27},{16,25},{41,79},{51,95},{46,47},{27,51},{31,44},{0,69},{61,63},{33,95},{17,88},{70,87},{40,42},{21,42},{67,77},{33,65},{3,25},{39,83},{34,40},{15,79},{30,90},{58,95},{45,56},{37,48},{24,91},{31,93},{83,90},{17,86},{61,65},{15,48},{34,56},{12,26},{39,98},{1,48},{21,76},{72,96},{30,69},{46,80},{6,29},{29,81},{22,77},{85,90},{79,83},{6,26},{33,57},{3,65},{63,84},{77,94},{26,90},{64,77},{0,3},{27,97},{66,89},{18,77},{27,43}};
    }
    int dfs(std::map<int, std::vector<int>>& grid, std::unordered_set<int>& visited, int row) {
        int nnodes = 0;
        for(int c: grid[row]) {
            if(visited.insert(c).second) {nnodes += 1+dfs(grid, visited, c); }
        }
        return nnodes;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //test(n, connections);
        int m = connections.size();
        if(m+1<n) return -1;
        std::map<int, std::vector<int>> grid;
        for(std::vector<int>& conn: connections) {
            int u = conn[0];
            int v = conn[1];
            grid[u].push_back(v);
            grid[v].push_back(u);
        }
        int nconnected = 0;
        std::unordered_set<int> visited;
        //for(int i = 0; i <= n; i++) {
            int start = connections[0][0];
         nconnected =  dfs(grid, visited, start);
            //nconnected = max(nconnected, dfs(grid, visited, start));
        //}
           //nconnected++; //nedges=nvertices-1 
        //printf("%d %d\n", n, nconnected );
        int nisolated = n-nconnected;
        return nisolated;
    }
};
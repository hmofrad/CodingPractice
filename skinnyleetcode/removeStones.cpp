/*
 *	https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dfs(std::unordered_map<int, std::vector<int>>& rows, std::unordered_map<int, std::vector<int>>& cols, unordered_set<int>& visited_rows, int row) {
        int res = 0;
        if(visited_rows.insert(row).second) {
            res += rows[row].size();
            for(auto c: rows[row]) 
                for(auto r: cols[c]) res += dfs(rows, cols, visited_rows, r);
        }
        return res;
    }
    int removeStones(vector<vector<int>>& stones) {
        std::unordered_map<int, std::vector<int>> rows, cols;
        std::unordered_set<int> visited_rows;
        int res = 0;
        for(std::vector<int>& stone: stones) {
            rows[stone[0]].push_back(stone[1]); 
            cols[stone[1]].push_back(stone[0]);
        }
        for(auto& row: rows) res+=max(0, dfs(rows, cols, visited_rows, row.first)-1);
        return res;
    }
    int union_find(std::vector<int>& unions, int a) {
        return unions[a] == -1 ? a : union_find(unions, unions[a]);
    }
    void union_merge(std::vector<int>& unions, int a, int b) {
        int u_a = union_find(unions, a);
        int u_b = union_find(unions, b);
        if(u_a != u_b) unions[u_a] = u_b;
    }
    int removeStones1(vector<vector<int>>& stones) {
        int nstones = 0;
        for(std::vector<int>& stone: stones) {
            nstones = stone[0] > nstones ? stone[0] : nstones;
            nstones = stone[1] > nstones ? stone[1] : nstones;
        }
        
        std::vector<int> unions(nstones+1, -1);
        for(std::vector<int>& stone: stones) {
            int u_a = union_find(unions, stone[0]);
            int u_b = union_find(unions, stone[1]);
            union_merge(unions, u_a, u_b);
        }
        
        
        return 0;
    }
};

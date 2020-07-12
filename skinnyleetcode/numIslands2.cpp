/*
 * https://leetcode.com/problems/number-of-islands-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 

class Solution {
public:
    
    int union_find(std::vector<int>& U, int u) {
        return U[u] == u ? u : union_find(U, U[u]);
    }
    
    bool union_merge(std::vector<int>& U, int u, int v) {
        int p_u = union_find(U, u);
        int p_v = union_find(U, v);
        if(p_u != p_v) { U[p_u] = p_v; return true;}
        return false;
    }
    
    bool is_valid(int row, int col, int nrows, int ncols) {
        return (row>=0 and row<nrows) and (col>=0 and col<ncols);
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        //m=3,n=3; positions = {{0,1},{1,2},{2,1},{1,0},{0,2},{0,0},{1,1}};
        //m=3,n=3; positions = {{0,0},{0,1},{1,2},{1,2}};
        int nrows = m;
        int ncols = n;
        std::vector<int> U(nrows*ncols, -1);
        std::vector<int> r = {0,0,1,-1};
        std::vector<int> c = {1,-1,0,0,};
        std::vector<int> counts;
        int count = 0;
        for(std::vector<int>& position: positions) {
            int row = position[0];
            int col = position[1];
            int index = row*ncols+col;
            //printf("%d\n", index);
            if(U[index] == index) {counts.push_back(count); continue; }
            U[index]=index;
            count++;
            

            std::vector<int> overlaps;
            for(int i = 0; i < 4; i++) {
                int r0 = row + r[i];
                int c0 = col + c[i];
                int pos = r0*ncols+c0;
                //printf("%d %d %d %d %d %d %d|", pos, is_valid(r0, c0, nrows, ncols), r0, c0, nrows, ncols, r0<nrows);
                if(is_valid(r0, c0, nrows, ncols) and U[pos] != -1) { 
                    //int u = union_find(U, index);
                    //int v = union_find(U, pos);
                    if(union_merge(U, index, pos)) { count--; }
                }
            }
            //printf("\n");
            //for(auto u: U) printf("%d ", u); printf("\n");
            counts.push_back(count);
        }
        
        return counts;
    }
    
};
class Solution0 {
public:
    
    int dfs(std::vector<std::vector<int>>& grid, int row, int col) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols) { return 0; }
        if(grid[row][col]==0) { return 0; }
        grid[row][col] = 0;
        int count = 1;
        std::vector<int> r = {0,0,1,-1};
        std::vector<int> c = {1,-1,0,0};
        for(int i = 0; i < 4; i++) {
            count += dfs(grid, row+r[i], col+c[i]);
        }
        //grid[row][col]=1;
        return count;
    }
    
    void print(std::vector<std::vector<int>>& grid) {
        for(auto& row: grid) {
            for(auto c: row) { printf("%d ", c); }
            printf("\n");
        }
        printf("\n");
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n));
        std::vector<int> counts;
        for(std::vector<int>& position: positions) {
            int row = position[0];
            int col = position[1];
            grid[row][col] = 1;
            std::vector<std::vector<int>> grid1 = grid;
            //print(grid1);
            int count = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(dfs(grid1, i, j)) { count++; }
                    
                }
            }
            counts.push_back(count);
            
        }
        return counts;
    }
};
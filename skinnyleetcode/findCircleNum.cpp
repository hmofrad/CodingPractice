/*
 *  https://leetcode.com/problems/friend-circles/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    int union_find(std::vector<int>& u, int a) {
        return u[a] == -1 ? a : union_find(u, u[a]);
    }
    
    void union_merge(std::vector<int>& u, int a, int b) {
        int ap = union_find(u, a);
        int bp = union_find(u, b);
        if(ap!=bp) u[ap]=bp;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int nrows = M.size();
        int ncols = nrows ? M[0].size() : 0;
        std::vector<int> u(nrows, -1);
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(M[i][j]) {
                    int a = union_find(u, i);
                    int b = union_find(u, j);
                    union_merge(u, a, b);
                }
            }
        }
        int cycles = 0;
        for(int a: u) cycles += a==-1 ? 1 : 0;
        return cycles;
    }
    
    int dfs(vector<vector<int>>& M, int row, int col, std::vector<bool>& visited) {
        int nrows = M.size();
        int ncols = nrows ? M[0].size() : 0;
        if(row<0 or row>=ncols or col<0 or col>=ncols) return 0;
        if(M[row][col]==0) return 0;
        M[row][col]=0;
        M[col][row]=0;
        visited[row]=true;
        for(int j = 0; j < ncols; j++) {
            if(M[row][j] and not visited[j]) {
                dfs(M, j, row, visited);
            }
            M[row][j]=0;
        }
        
        return 1;
    }
    
    void print(vector<vector<int>>& M) {
        int nrows = M.size();
        int ncols = nrows ? M[0].size() : 0;
        int circles = 0;
        printf("\n");
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    int findCircleNum1(vector<vector<int>>& M) {
        int nrows = M.size();
        int ncols = nrows ? M[0].size() : 0;
        int circles = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(M[i][j]) {
                    //printf("%d %d %d\n", i, j, circles);
                    std::vector<bool> visited(nrows);
                    circles += dfs(M, i, j, visited);
                    //print(M);
                }
            }
        }
        return circles;
    }
};
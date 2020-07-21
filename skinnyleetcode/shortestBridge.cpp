/*
 * https://leetcode.com/problems/shortest-bridge/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void print(vector<vector<int>>& A) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    bool paint(vector<vector<int>>& A, int row, int col) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or A[row][col] != 1) { return false; }
        A[row][col]=2;
        paint(A, row+1, col), paint(A, row-1, col), paint(A, row, col+1), paint(A, row, col-1);
        return true;
    }
    
    bool expand(vector<vector<int>>& A, int row, int col, int color) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols) { return false; }
        if(A[row][col]==0) { A[row][col] = color + 1;}
        return A[row][col]==1;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        //A = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
        //A = {{1,1,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
        //print(A);
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        if(nrows == 0 or ncols == 0) { return 0; }
        
        bool b = false;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                b = paint(A, i, j); 
                if(b){break;}
            }
            if(b){break;}
        }
        //print(A);
        
        int color = 2;
        while(true) {
            for(int i = 0; i < nrows; i++) {
                for(int j = 0; j < ncols; j++) {
                    if((A[i][j]==color) and
                       ((expand(A, i-1, j, color)) or 
                        (expand(A, i+1, j, color)) or 
                        (expand(A, i, j-1, color)) or 
                        (expand(A, i, j+1, color)))) { /*print(A);*/ return color-2; }
                }
            }
            color++;
        }
        
        return 0;
    }
};

class Solution0 {
public:
    void dfs(vector<vector<int>>& A, int row, int col, std::set<std::pair<int,int>>& island) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or A[row][col]==0) { return; }
        A[row][col] = 0;
        island.insert({row,col});
        std::vector<int> r = {0,0,1,-1};
        std::vector<int> c = {1,-1,0,0};
        for(int i = 0; i < 4; i++) {
            dfs(A, row+r[i], col+c[i], island);
        }
    }
        
    void islands(vector<vector<int>>& A, std::set<std::pair<int,int>>& island1, std::set<std::pair<int,int>>& island2) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(A[i][j] and island1.empty()) { dfs(A, i, j, island1); }
                else if(A[i][j] and island2.empty()) { dfs(A, i, j, island2); }
            }
        }
    }
    
    int dfs0(std::set<std::pair<int,int>>& island1, std::set<std::pair<int,int>>& island2, std::set<std::pair<int,int>>& bridge, int row, int col, int nrows, int ncols) {
        if(row<0 or row>=nrows or col<0 or col>=ncols or island1.count({row, col}) or bridge.count({row, col})) { return INT_MAX; }
        if(island2.count({row, col})) { return bridge.size(); }
        
        bridge.insert({row,col});
        std::vector<int> r = {0,0,1,-1};
        std::vector<int> c = {1,-1,0,0};
        int cost = INT_MAX;
        for(int i = 0; i < 4; i++) {
            int t = dfs0(island1, island2, bridge, row+r[i], col+c[i], nrows, ncols);
            cost = min(cost, t);
        }
           
        bridge.erase({row,col});
        return cost;
    }
    
    int connect(std::set<std::pair<int,int>>& island1, std::set<std::pair<int,int>>& island2, int nrows, int ncols) {
        int cost = INT_MAX;
        for(std::pair<int, int> p: island1) {
            int row = p.first;
            int col = p.second;
            
            std::vector<int> r = {0,0,1,-1};
            std::vector<int> c = {1,-1,0,0};
            for(int i = 0; i < 4; i++) {
                std::set<std::pair<int,int>> bridge;
                cost = min(cost, dfs0(island1, island2, bridge, row+r[i], col+c[i], nrows, ncols));
            }
        }
        return cost; 
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        if(A.empty() or A[0].empty()) { return 0; }
        //A = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
        std::set<std::pair<int,int>> island1;
        std::set<std::pair<int,int>> island2;
        islands(A, island1, island2);
        
        
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        return island1.size() < island2.size() ? connect(island1, island2, nrows, ncols) : connect(island2, island1, nrows, ncols);
        
        
        /*
        if(nrows == 0 or ncols == 0) { return 0; }
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        
        return 0;
        */
    }
};
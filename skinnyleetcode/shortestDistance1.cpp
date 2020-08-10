/*
 * https://leetcode.com/problems/shortest-distance-from-all-buildings/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        if(nrows == 0 or ncols == 0) { return -1; }
        
        std::vector<int> r = {0,0,-1,1};
        std::vector<int> c = {-1,1,0,0};
        
        std::vector<std::vector<int>> distance(nrows, std::vector<int>(ncols));
        std::vector<std::vector<int>> reachable(nrows, std::vector<int>(ncols));
        
        int nbuildings = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j] == 1) { 
                    nbuildings++; 
                    std::queue<int> queue;
                    std::unordered_set<int> visited;
                    queue.push(i*ncols+j);
                    int level = 1;
                    while(not queue.empty()) {
                        int size = queue.size();
                        for(int k = 0; k < size; k++) {
                            int front = queue.front(); queue.pop();
                            for(int l = 0; l < 4; l++) {
                                int row = front/ncols + r[l];
                                int col = front%ncols + c[l];
                                int x = row*ncols+col;
                                if(row>=0 and row<nrows and col>=0 and col<ncols and grid[row][col]==0 and visited.insert(x).second) {
                                    queue.push(x);
                                    distance[row][col] += level;
                                    reachable[row][col]++;
                                }
                            }
                        }
                        level++;
                    }
                }
                
            }
        }
        
        int shortest = INT_MAX;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j]==0 and reachable[i][j] == nbuildings) { shortest = min(shortest, distance[i][j]); }
            }
        }
        
        return shortest==INT_MAX ? -1 : shortest;
    }
    
    
    int dfs(vector<vector<int>>& grid, int row, int col, int building, std::unordered_set<int>& visited, int cost) {
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or grid[row][col]==2) { return INT_MAX; }
        int x = row*ncols + col;
        if(x == building) { return cost; }
        if(cost != 0 and grid[row][col]==1) { return INT_MAX; }
        if(visited.insert(x).second == false) { return INT_MAX; }
        std::vector<int> r = {0, 0, -1, 1};
        std::vector<int> c = {-1, 1, 0, 0};
        int path = INT_MAX;
        for(int i = 0; i < 4; i++) {
            int ret = dfs(grid, row+r[i], col+c[i], building, visited, cost+1);
            path = min(path, ret);
        }
        visited.erase(x);
        return path;
    }
    int shortestDistance0(vector<vector<int>>& grid) {
        std::unordered_set<int> buildings;
        int nrows = grid.size();
        int ncols = nrows ? grid[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j]==1) { buildings.insert(i*ncols+j); }
            }
        }
        int c = INT_MAX;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(grid[i][j] == 0) {
                    int cost = 0;
                    for(int b: buildings){
                        std::unordered_set<int> visited;
                        int r = dfs(grid, i, j, b, visited, 0);
                        if(r == INT_MAX) {cost=-1; break; }
                        else { cost += r; }
                    }
                    if(cost!=-1) { c = min(c, cost); }
                }
            }
        }
        
        
        return c==INT_MAX ? -1 : c;
    }
};
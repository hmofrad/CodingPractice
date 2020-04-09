/*
 *  https://leetcode.com/problems/keys-and-rooms/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int i, std::vector<bool>& visited, bool& reached, int& count) {
        if(visited[i]) return;
        visited[i] = true;
        count++;
        if(count == rooms.size()) {reached = true; return;}
        
        for(int j = 0; j < rooms[i].size(); j++) {
            dfs(rooms, rooms[i][j], visited, reached, count);
            if(reached) return;
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::vector<bool> visited(rooms.size());
        bool reached = false;
        int count = 0;
        dfs(rooms, 0, visited, reached, count);
        return(reached);
    }
    
    
    bool canVisitAllRooms2(vector<vector<int>>& rooms) {
        std::vector<bool> seen(rooms.size());
        seen[0] = true;
        
        std::vector<int> stack;
        stack.push_back(0);
        
        while(not stack.empty()) {
            int node = stack.back();
            stack.pop_back();
            std::vector<int> row = rooms[node];
            for(int col: row) {
                if(not seen[col]) {
                    seen[col] = true;
                    stack.push_back(col);
                }
            }
        }
        bool tf = true;
        for(bool s: seen) {
            if(s == false) {tf = false; break;}
        }
        
        return(tf);
    }
    
    
    int nrows;
    int ncols;
    vector<vector<int>> grid;
    
    bool converged(std::vector<bool> visited) {
        return(std::accumulate(visited.begin(), visited.end(), 0) == nrows);
    }
    
    void traverse(int row, int col, std::vector<bool>& visited) {
        //if(row > nrows and col > ncols) return;
       // printf("%d %d\n", row, col);
        for(int j = 0; j < ncols; j++) {
            if(grid[row][j] and not visited[j]) {visited[row] = true; traverse(j, row, visited);}
        }
        visited[row] = true;
    }
    
    bool canVisitAllRooms1(vector<vector<int>>& rooms) {
        //if(rooms.empty() or rooms[0].empty()) return true;
        nrows = rooms.size();
        ncols = rooms.size();
        grid.resize(nrows);
        for(std::vector<int>& row: grid) {
            row.resize(ncols);
        }
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < rooms[i].size(); j++) {
                grid[i][rooms[i][j]] = 1;
                grid[rooms[i][j]][i] = 1;
            }
        }
        if(nrows == 1) return true;
        //std::vector<bool> visited;
        //traverse(0, visited);
        
        int ncs = (nrows) ? rooms[0].size() : 0;
        for(int j = 0; j < ncs; j++) {
            std::vector<bool> visited(nrows);
            visited[0] = true;
            traverse(rooms[0][j], 0, visited);
            if(converged(visited)) return(true);
            //printf("[%d %d]: ", rooms[0][j]); for(bool b: visited) printf("%d ", b); printf("\n");
        }
        
        return(false);
    }
};
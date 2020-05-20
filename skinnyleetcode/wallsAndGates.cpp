/*
 *	https://leetcode.com/problems/walls-and-gates/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    const int INF = 2147483647;
    
    void wallsAndGates1(vector<vector<int>>& rooms) {
        std::queue<std::pair<int, int>> queue;
        int nrows = rooms.size();
        int ncols = nrows ? rooms[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(rooms[i][j]==0) queue.push({i, j});
            }
        }
        
        std::vector<std::pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(not queue.empty()) {
            int row = 0, col = 0;
            std::tie(row, col) = queue.front(); queue.pop();
            for(std::pair<int, int>& d: directions) {
                int r = row+d.first, c = col+d.second;
                if(r<0 or r>=nrows or c<0 or c>=ncols or rooms[r][c]!=INF) continue;
                rooms[r][c]=rooms[row][col]+1;
                queue.push({r,c});
            }
        }
    }
    
    
    
    
    
    void print(vector<vector<int>>& rooms) {
        int nrows = rooms.size();
        int ncols = nrows ? rooms[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", rooms[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    
    int distance(std::pair<int, int> room, std::pair<int, int> gate) {
        return (abs(room.first - gate.first) + abs(room.second - gate.second));
    }
    
    void dfs1(vector<vector<int>>& rooms, std::pair<int, int> source_room, std::set<std::pair<int, int>>& visited, int row, int col, int dist) {
        int nrows = rooms.size();
        int ncols = nrows ? rooms[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols or not visited.insert({row,col}).second or rooms[row][col]==-1) return;
        
        if(rooms[row][col]==0 and source_room.first!=row and source_room.second!=col) return;
        
        
        if(rooms[row][col]>0) {
            rooms[row][col] = rooms[row][col] == INF ? dist : min(rooms[row][col], dist);
            return;
        }
            
        
        dfs1(rooms, source_room, visited, row+1, col, dist+1), 
        dfs1(rooms, source_room, visited, row-1, col, dist+1),
        dfs1(rooms, source_room, visited, row, col-1, dist+1),
        dfs1(rooms, source_room, visited, row, col+1, dist+1);
        
        return;
    }
    
    void dfs(vector<vector<int>>& rooms, int row, int col, int dist) {
        int nrows = rooms.size();
        int ncols = nrows ? rooms[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols) return;
        if(rooms[row][col]<dist) return;
        rooms[row][col]=dist;
        dfs(rooms, row+1, col, dist+1), 
        dfs(rooms, row-1, col, dist+1),
        dfs(rooms, row, col-1, dist+1),
        dfs(rooms, row, col+1, dist+1);
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int nrows = rooms.size();
        int ncols = nrows ? rooms[0].size() : 0;
        
        
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                std::set<std::pair<int, int>> visited;
                if(rooms[i][j] == 0) dfs(rooms, i, j, 0);
                //if(rooms[i][j] == 0) dfs(rooms, std::make_pair(i,j), visited, i,j, 0);
            }
        }
        //print(rooms);    
    }
};
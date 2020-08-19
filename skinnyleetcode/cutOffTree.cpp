/*
 * https://leetcode.com/problems/cut-off-trees-for-golf-event/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int bfs(vector<vector<int>>& forest, int s_row, int s_col, int d_row, int d_col) {
        if(s_row == d_row and s_col == d_col) { return 0; }
        int nrows = forest.size();
        int ncols = nrows ? forest[0].size() : 0;
        std::vector<int> rd = {0,0,-1,1};
        std::vector<int> cd = {-1,1,0,0};
        std::queue<std::pair<int, int>> queue;
        queue.push({s_row, s_col});
        std::vector<std::vector<bool>> visited(nrows, std::vector<bool>(ncols));
        visited[s_row][s_col]=true;
        int counts = 0;
        
        while(not queue.empty()) {
            counts++;
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                int row = 0, col = 0;
                std::tie(row, col) = queue.front(); queue.pop();
                
                for(int j = 0; j < 4; j++) {
                    int r = row+rd[j];
                    int c = col+cd[j];
                    if(r<0 or r>=nrows or c<0 or c>=ncols or forest[r][c]==0 or visited[r][c] == true) {
                        continue;
                    }
                    if(r == d_row and c == d_col) { return counts; }
                    visited[r][c]=true;
                    queue.push({r,c});
                }
            }
            
        }
        
        return -1;
    }
    
    struct comp {
        bool operator()(const std::pair<int, std::pair<int,int>>& a, const std::pair<int, std::pair<int,int>>& b) {
            return a.first > b.first;
        }  
    };
    
    int cutOffTree(vector<vector<int>>& forest) {
        int nrows = forest.size();
        int ncols = nrows ? forest[0].size() : 0;
        
        std::priority_queue<std::pair<int, std::pair<int,int>>, std::vector<std::pair<int, std::pair<int,int>>>, comp> pq;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(forest[i][j]>1) { pq.push({forest[i][j], {i,j}}); }
            }
        }

        int count = 0;
        int s_row = 0;
        int s_col = 0;
        while(not pq.empty()) {
            int d_row = 0, d_col = 0;
            std::tie(d_row, d_col) = pq.top().second; pq.pop();
            int r = bfs(forest, s_row, s_col, d_row, d_col);
            //printf("%d %d %d %d %d\n", s_row, s_col, d_row, d_col, r);
            if(r == -1) { return -1; }
            count += r;
            s_row = d_row;
            s_col = d_col;
        }
        return count; 
        
        /*
        std::map<int, std::pair<int,int>> map;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(forest[i][j]>1) map[forest[i][j]]={i,j};
            }
        }
        int count = 0;
        int s_row = 0;
        int s_col = 0;
        for(auto m: map) {
            int d_row = m.second.first, d_col = m.second.second;
            int r = bfs(forest, s_row, s_col, d_row, d_col);
            //printf("%d %d %d %d %d\n", s_row, s_col, d_row, d_col, r);
            if(r == -1) { return -1; }
            count += r;
            s_row = d_row;
            s_col = d_col;
        }
        return count;
        */
    }
};  


class Solution0 {
public:
    int dfs(vector<vector<int>>& forest, int src, int dst, std::unordered_set<int>& visited) {
        if(src == dst) { return 0; }
        if(visited.insert(src).second == false) { return -1; }
        
        int nrows = forest.size();
        int ncols = nrows ? forest[0].size() : 0;
        int r = src/ncols;
        int c = src%ncols; 
        
        if(forest[r][c] == 0) { return -1; }
        
        std::vector<int> rd = {0,0,-1,1};
        std::vector<int> cd = {-1,1,0,0};
        int ans = INT_MAX;
        for(int i = 0; i < 4; i++) {
            int row = r+rd[i];
            int col = c+cd[i];
            if(row<0 or row>=nrows or col<0 or col>=ncols or forest[row][col]<1) { continue; }
            int ret = dfs(forest, row*ncols+col, dst, visited);
            if(ret != -1) {  ret += 1; ans = min(ans, ret);}
        }
        visited.erase(src);
        return ans == INT_MAX ? -1 : ans;
    }
    
    int bfs(vector<vector<int>>& forest, int src, int dst, std::unordered_set<int>& visited) {
        int nrows = forest.size();
        int ncols = nrows ? forest[0].size() : 0;
        std::vector<int> rd = {0,0,-1,1};
        std::vector<int> cd = {-1,1,0,0};
        
        int counts = 0;
        std::queue<int> queue;
        queue.push(src);
        visited.insert(src);
        while(not queue.empty()) {
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                int front = queue.front(); queue.pop();
                if(front == dst) { return counts; }
                
                int r = front/ncols;
                int c = front%ncols;
                
                for(int j = 0; j < 4; j++) {
                    int row = r+rd[j];
                    int col = c+cd[j];
                    int temp = row*ncols+col;
                    if(row<0 or row>=nrows or col<0 or col>=ncols or forest[row][col]<1 or visited.insert(temp).second == false) { continue; }
                    queue.push(temp);
                }
            }
            counts++;
        }
        return -1;
    }


    int cutOffTree(vector<vector<int>>& forest) {
        int nrows = forest.size();
        int ncols = nrows ? forest[0].size() : 0;
        std::map<int, int> map;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                if(forest[i][j]>1) map[forest[i][j]]=i*ncols+j;
            }
        }

        int count = 0;
        int src = 0;
        int i = 0;
        for(auto m: map) {
            int h = m.first;
            int dst = m.second;
            std::unordered_set<int> visited;
            //int r = dfs(forest, src, dst, visited);
            int r = bfs(forest, src, dst, visited);
            //printf("%d %d %d\n", src, dst, r);
            if(r == -1) { return -1; }
            count += r;
            src = dst;
        }
        return count; 
    }
};
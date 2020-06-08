/*
 * https://leetcode.com/problems/android-unlock-patterns/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dfs(int num, int len, int count, int m, int n, std::vector<std::vector<int>>& jumps, std::vector<bool>& visited) {
        if(len>=m) count++;
        len++;
        if(len>n) return count;
        visited[num]=true;
        for(int i = 1; i <= 9; i++) {
            int jump = jumps[num][i];
            if(not visited[i] and (jump==0 or visited[jump])) {
                count = dfs(i, len, count, m, n, jumps, visited);
            }
        }
        visited[num]=false;
        return count;
    }
    
    int numberOfPatterns(int m, int n) {
        std::vector<std::vector<int>> jumps(10, std::vector<int>(10));
        std::vector<bool> visited(10);
        jumps[1][3]=jumps[3][1]=2;
        jumps[4][6]=jumps[6][4]=5;
        jumps[7][9]=jumps[9][7]=8;
        jumps[1][7]=jumps[7][1]=4;
        jumps[2][8]=jumps[8][2]=5;
        jumps[3][9]=jumps[9][3]=6;
        jumps[1][9]=jumps[9][1]=5;
        jumps[3][7]=jumps[7][3]=5;
        
        int count = 0;
        count += dfs(1, 1, 0, m, n, jumps, visited)*4;
        count += dfs(2, 1, 0, m, n, jumps, visited)*4;
        count += dfs(5, 1, 0, m, n, jumps, visited);
        return count;
    }
};
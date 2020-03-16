/*
 *  Problem: https://leetcode.com/problems/max-increase-to-keep-city-skyline/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (m) ? grid[0].size() : 0;
        std::vector<int> left_skyline(m);
        std::vector<int> bottom_skyline(n);
        for(int i = 0; i < m; i++) {
            //int mx = 0;
            //mx = (grid[i][j] > mx) ? grid[i][j] : mx;
            for(int j = 0; j < n; j++) {
                left_skyline[i] = (left_skyline[i] < grid[i][j]) ? grid[i][j] : left_skyline[i];
                bottom_skyline[j] = (bottom_skyline[j] < grid[i][j]) ? grid[i][j] : bottom_skyline[j];
                
            }
            //left_skyline[i] = mx;
        }
        /*
        std::vector<int> bottom_skyline(n);
        for(int j = 0; j < n; j++) {
            int mx = 0;
            for(int i = 0; i < m; i++) {
                mx = (grid[i][j] > mx) ? grid[i][j] : mx;
            }
            bottom_skyline[j] = mx;
        }
        */
        int diff = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int mn = min(left_skyline[i], bottom_skyline[j]);
                diff += (grid[i][j] < mn) ? mn - grid[i][j] : 0;
            }
        }
        
        return(diff);
    }
};
/*
 *  https://leetcode.com/problems/matrix-cells-in-distance-order/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int r;
    int c;
    vector<vector<int>> allCellsDistOrder1(int R, int C, int r0, int c0) {
        r = r0;
        c = c0;
        vector<vector<int>> poss(R*C, std::vector<int>(2));
        vector<vector<int>> dists(R*C, std::vector<int>(2));
        int k = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                int d = abs(i-r) + abs(j-c);
                dists[k] = {i,j};
                k++;
            }
        }
        
        std::sort(poss.begin(), poss.end(), [this](std::vector<int> a, std::vector<int> b) {
            int da = abs(a[0]-r) + abs(a[1]-c);
            int db = abs(b[0]-r) + abs(b[1]-c);
            return(da < db);
        });
        
        return(dists);
    }
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        std::vector<std::vector<int>> ans(R*C);
        std::vector<int> dists(R+C-1);
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                int d = abs(i-r0) + abs(j-c0);
                dists[d]++;
            }
        }
        
        int sum = 0;
        for(int i = 0; i < dists.size(); i++) {
            sum += dists[i];
            dists[i] = sum;
        }
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                int d = abs(i-r0) + abs(j-c0);
                ans[--dists[d]] = {i,j};
                //dists[d]--;
            }
        }
        
        return(ans);
        
    }
    
    
    
};
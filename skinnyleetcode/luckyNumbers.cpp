/*
 *  Problem: https://leetcode.com/problems/lucky-numbers-in-a-matrix/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckiest;
        int m = matrix.size();
        int n = (m) ? matrix[0].size() : 0;
        if(m) {
            std::vector<int> mins(m);
            for(int i = 0; i < m; i++) {
                mins[i] = *std::min_element(matrix[i].begin(), matrix[i].end());
            }
            std::vector<int> maxes(n);
            if(n) {
                for(int j = 0; j < n; j++) {
                    for(int i = 0; i < m; i++) {
                        if(matrix[i][j] > maxes[j]) {
                            maxes[j] = matrix[i][j];
                        }
                    }
                }
            }
            
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] == mins[i] and matrix[i][j] >= maxes[j]) {
                        luckiest.push_back(matrix[i][j]);
                    }
                }
            }
            
        }
        

        return(luckiest);
    }
};

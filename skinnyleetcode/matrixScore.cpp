/*
 *  https://leetcode.com/problems/score-after-flipping-matrix/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int get_vec_value(vector<int> vec) {
        int n = vec.size();
        int v = 0;
        for(int i = 0; i < n; i++) {
            v += (vec[i]) ? pow(2, n-i-1) : 0;
        }
        return(v);
    }
    int get_grid_value(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = (m) ? mat[0].size() : 0;
        int v = 0;
        for(int i = 0; i < m; i++) {
            v += get_vec_value(mat[i]);
        }
        return(v);
    }
    
    std::vector<int> toggle(std::vector<int> vec) {
        int n = vec.size();
        for(int i = 0; i < n; i++) {
            vec[i] = not vec[i];
        }
        return(vec);
    }
    
    int max(int a, int b) {return(a>b ? a : b);}
    
    

    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = (m) ? A[0].size() : 0;
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            if(not A[i][0]) {
                for(int j = 0; j < n; j++) {
                    A[i][j] = not A[i][j];
                }
            }
        }
        int s = pow(2, n-1) * m;
        
        for(int j = 1; j < n; j++) {
            int count = 0;
            for(int i = 0; i < m; i++) {
                if(not A[i][j]) count++;
            }
            s += pow(2,n-1-j) * max(count, m-count);
        }
        
        return(s);
        
    }
    
    
    int matrixScore1(vector<vector<int>>& A) {
        int m = A.size();
        int n = (m) ? A[0].size() : 0;
        int ans = 0;
        for(int j = 0; j < n; j++) {
            int col = 0;
            for(int i = 0; i < m; i++) {
                col += A[i][j] ^ A[i][0];
            }
            ans += max(col, m-col) *(1 << (n-1-j));
        }
        return(ans);
    }
    
};

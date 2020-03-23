/*
 *  https://leetcode.com/problems/find-smallest-common-element-in-all-rows/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int smallestCommonElement1(vector<vector<int>>& mat) {
        if(mat.empty()) return(-1);
        int m = mat.size();
        int n = (m) ? mat[0].size() : 0;
        /*
        for(int i = 0; i < m; i++) {
            std::sort(mat[i].begin(), mat[i].end());
        }
        */
        std::vector<int> indices(m);
        int min_v = -1;
        bool b = false;
        while(true) {
            for(int i = 0; i < m; i++) {
                if(indices[i] == n) {
                    b = true;
                    break;
                }
            }
            if(b) break;
            
            int min = mat[0][indices[0]];
            for(int i = 1; i < m; i++) {
                if(mat[i][indices[i]] < min) {
                    min = mat[i][indices[i]];
                }
            }
            int c = 0;
            for(int i = 0; i < m; i++) {
                if(mat[i][indices[i]] == min) {
                    indices[i]++;
                    c++;
                }
            }
           // printf("%d %d %d\n", min, c, indices[0]);
            if(c == m) {
                min_v = min;
                break;
            }
        }
        
        return(min_v);   
    }
    
    bool binary_search(std::vector<int> vec, int val) {
        bool found = false;
        int left = 0;
        int right = vec.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(val < vec[mid]) {
                right = mid-1;
            }
            else if( val > vec[mid]) {
                left = mid+1;
            }
            else {
                found = true;
                break;
            }
        }
        return(found);
    }
    
    int smallestCommonElement(vector<vector<int>>& mat) {
        if(mat.empty()) return(-1);
        int m = mat.size();
        int n = (m) ? mat[0].size() : 0;
        
        int min = -1;
        for(int j = 0; j < n; j++) {
            int val = mat[0][j];
            bool found = true;
            for(int i = 1; i < m; i++) {
                if(not binary_search(mat[i], val)) {
                    found = false;
                    break;
                }
            }
            if(found) {
                min = val;
                break;
            }
        }
        
        return(min);
        
    }
    
    
};
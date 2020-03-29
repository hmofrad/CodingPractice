/*
 *  https://leetcode.com/problems/delete-columns-to-make-sorted/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int d = 0;
        int m = A.size();
        int n = (m) ? A[0].length() : 0;
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m-1; i++) {
                if(A[i][j] > A[i+1][j]) {
                    //printf("%d %d %d %c %c\n", i, j, d, A[i][j], A[i][j+1]);
                    d++;
                    break;
                }
            }
        }
        return(d);
    }
};
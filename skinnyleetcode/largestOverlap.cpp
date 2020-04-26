/*
 *  https://leetcode.com/problems/image-overlap/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    int compare(vector<vector<int>>& A, vector<vector<int>>& B, int row, int col) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        int count = 0;
        for(int i = 0; i < nrows and i+row<nrows; i++) {
            for(int j = 0; j < ncols and j+col < ncols; j++) {
                if(A[i][j]==1 and B[i+row][j+col]==1) count++;
            }
        }    
        return count;
    }

    void print(vector<vector<int>> A) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    vector<vector<int>> slide(vector<vector<int>>& A, int type, int left, int right, int up, int down) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        vector<vector<int>> A0(nrows, std::vector<int>(ncols));
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                int j1 =abs(j-ncols-1);
                int l = max(j-left, 0);
                int r = min(0, j1-right);
                int u = max(0,i-up);
                int d = min(nrows-1,i+down);
                int row = i, col = j;
                switch(type){
                    case 0: col=l; break;
                    case 1: col=r; j=j1; break;
                    case 2: row=u; break;
                    case 3: row=d; break;
                    default: break;
                }
                A0[row][col]=A[i][j];
            }
        }   
        return A0;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int nrows = A.size();
        int ncols = nrows ? A[0].size() : 0;
        //int nmoves = nrows * ncols;
        //print(A); print(B);
        //print(slide(A, 1, 1, 1,1,1));
        int nmoves = 0;
        for(int i = 0; i < nrows; i++) {
            for(int j = 0; j < ncols; j++) {
                nmoves = max({nmoves, compare(A, B, i, j), compare(B, A, i, j)});
            }
        }
        
        
        
        return nmoves;
    }
};
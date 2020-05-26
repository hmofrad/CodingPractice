/*
 *	https://leetcode.com/problems/spiral-matrix-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void print(vector<vector<int>> mat) {
        printf("\n");
        for(auto row: mat) {
            for(auto c: row){
                printf("%d ", c);
            }
            printf("\n");
        }
        printf("\n");
    }
    vector<vector<int>> generateMatrix(int n) {
       // n=5;
        std::vector<std::vector<int>> mat(n, std::vector<int>(n));
        int ndiags = (n+2-1)/2;
        //printf("nd=%d\n", ndiags);
        int l = 0;
        for(int d = 0; d < ndiags; d++) {
            //printf(">>d=%d\n\n", d);
            //int l = d*(n-1-d)*4;
            //printf("d=%d l=%d\n", d, l);
            //for(int j = d; j <= n-1-d; j++) {mat[d][j]=l+j+1; l++;}
            for(int j = d; j <= n-1-d; j++) {mat[d][j]=++l;}
            //l += n-d;
            //printf("2.l=%d\n", l);
            //for(int i = d+1; i <= n-1-d; i++) {mat[i][n-1-d]=l+i;}
            for(int i = d+1; i <= n-1-d; i++) {mat[i][n-1-d]=++l;}
            //l += n-1-d;
            //printf("3.l=%d\n", l);
            //for(int j = n-2-d; j >= d; j--) {mat[d][j]=l+j-n-1-d;}
            for(int j = n-2-d; j >= d; j--) {mat[n-1-d][j]=++l;}
            //l+= n-1-d;
            
            //printf("4.l=%d\n", l);
            for(int i = n-2-d; i > d; i--) {mat[i][d]=++l;}
            //printf("5.l=%d\n", l);
            //print(mat);
            //break;
            //printf("%d\n", d);
        }
        return mat;
    }
};
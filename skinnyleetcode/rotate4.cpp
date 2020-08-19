/*
 * https://leetcode.com/problems/rotate-image/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        //print(matrix);
        int n = matrix.size();
        int d = n/2;
        
        for(int i = 0; i < d; i++) {
            for(int j = 0; j < n-(i*2)-1; j++) {
                std::swap(matrix[i][i+j], matrix[n-i-1-j][i]);
                std::swap(matrix[n-i-1-j][i], matrix[n-i-1][n-i-1-j]);
                std::swap(matrix[n-i-1][n-i-1-j], matrix[i+j][n-i-1]);
            }   
        }

    }
    
    
    
    void rotate4(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
    
    
    void rotate3(vector<vector<int>>& matrix) {
        //matrix={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        //print(matrix);
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int d = m/2;
        for(int k = 0; k < d; k++) {
            int ncols = n-(k*2)-1;
            //printf("k=%d %d\n", k, ncols);
            for(int j = 0; j < ncols; j++) {
                //printf("[%d %d]\n", k, k+j);
                //printf("[%d %d]\n", k+j,n-k-1);
                //printf("[%d %d]\n", n-k-1,n-k-1-j);
                //printf("[%d %d]\n", n-k-1-j, k);
                
                int t = matrix[k+j][n-k-1];
                matrix[k+j][n-k-1]=matrix[k][k+j];
                std::swap(t, matrix[n-k-1][n-k-1-j]);
                std::swap(t, matrix[n-k-1-j][k]);
                std::swap(t, matrix[k][k+j]);
                
                
            }
        }

    }
    
    
    void rotate1(vector<vector<int>>& matrix, int d) {
        int n = matrix.size();
        int temp = matrix[d][n-1-d];
        //printf(">>%d %d %d\n", n, d, temp);
        for(int j=n-1-d; j>d; j--)   matrix[d][j]=matrix[d][j-1];
        for(int i=d+1; i<n-d; i++) matrix[i-1][d]=matrix[i][d];
        for(int j=d+1; j<n-d; j++)   matrix[n-1-d][j-1]=matrix[n-1-d][j];
        for(int i=n-1-d; i>d+1; i--)   matrix[i][n-1-d]=matrix[i-1][n-1-d];
        matrix[d+1][n-1-d]=temp;
    }
    void print(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int d = n/2;
       // print(matrix);
        for(int i = 0; i < d; i++) {
            int j = i*2;
            for(int t = 0; t < n-1-j; t++) {
                rotate1(matrix, i);
                //printf("%d %d\n",i, t);
                //print(matrix);
            }

        }
    }
    
    
    void rotate1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        //print(matrix);
        for(int i = 0; i < n; i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
        //print(matrix);
    }  
};


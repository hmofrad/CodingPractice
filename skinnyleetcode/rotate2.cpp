/*
 *	https://leetcode.com/problems/rotate-image/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

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
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int d = n/2;
	print(matrix);
	for(int i = 0; i < d; i++) {
		int j = i*2;
		for(int t = 0; t < n-1-j; t++) {
			rotate1(matrix, i);
			printf("%d %d\n",i, t);
		    print(matrix);
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
/*
[[15,13,2,5],
 [14,3,4,1],
 [12,6,8,9],
 [16,7,10,11]]
*/
int main() {
	vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	rotate(matrix);
	return 0;
}

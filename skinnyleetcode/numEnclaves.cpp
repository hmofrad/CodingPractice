/*
 *	https://leetcode.com/problems/number-of-enclaves/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void dfs1(vector<vector<int>>& A, int row, int col) {
	int nrows = A.size();
	int ncols = (nrows) ? A[0].size() : 0;
	if(row<0 or row>=nrows or col<0 or col>=ncols or A[row][col]!=1) return;
    A[row][col]=0;
    dfs1(A,row+1, col), dfs1(A, row-1, col), dfs1(A,row, col+1), dfs1(A, row, col-1);
}
    
int numEnclaves1(vector<vector<int>>& A) {
	int nrows = A.size();
	int ncols = (nrows) ? A[0].size() : 0;
    for(int i = 0; i < nrows; i++) {
        for(int j = 0; j < ncols; j++) {
            if(i==0 or i==nrows-1 or j==0 or j==ncols-1) {
                dfs1(A,i, j);
            }
        }
    }
    int count = 0;
    for(int i = 0; i < nrows; i++) {
        for(int j = 0; j < ncols; j++) {
            count += A[i][j] ? 1 : 0;
        }
    }
    return count; 
}
    

int dfs(vector<vector<int>>& A, int row, int col, int& sum) {
	//printf("%d %d %d\n", row, col, sum);
	int nrows = A.size();
	int ncols = (nrows) ? A[0].size() : 0;
	if(row<0 or row>=nrows or col<0 or col>=ncols) return false;
	if(A[row][col]==0) return true;
	//if(A[row][col]==0 or A[row][col]==2) return true;
	A[row][col]=0;
	sum=sum+1;
	bool ans1 = dfs(A, row, col-1, sum);
	bool ans2 = dfs(A, row, col+1, sum);
	bool ans3 = dfs(A, row-1, col, sum);
	bool ans4 = dfs(A, row+1, col, sum);
	bool ans = ans1 and ans2 and ans3 and ans4;
	return ans;
}

void print(vector<vector<int>>& A) {
	int nrows = A.size();
	int ncols = (nrows) ? A[0].size() : 0;
	
	for(int i = 0; i < nrows; i++) {
		for(int j = 0; j < ncols; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int numEnclaves(vector<vector<int>>& A) {
	int nrows = A.size();
	int ncols = (nrows) ? A[0].size() : 0;
    //print(A);
	/*
	//int count = 0;
	for(int i = 0; i < nrows; i++) {
		for(int j = 0; j < ncols; j++) {
			//if(A[i][j]) count++;
			if((i==0 or i==nrows-1 or j==0 or j==ncols-1) and not A[i][j]) {
				A[i][j] = 2;
			}
		}
	}
	print(A);printf("\n");
	*/
	int count = 0;
	for(int i = 0; i < nrows; i++) {
		for(int j = 0; j < ncols; j++) {
			if(A[i][j]==1) {
				int sum = 0;
				bool ans = dfs(A, i, j, sum);
				printf("%d %d %d %d %d\n", i, j, ans, count, sum);
				//print(A);
				count += ans ? sum : 0;
				//break;
			}
		}
		//break;
	}
   // print(A);
	
	
	return count; 
}


int main() {
	std::vector<std::vector<int>> A = {{0,0,0,1,1,1,0,1,0,0},
{1,1,0,0,0,1,0,1,1,1},
{0,0,0,1,1,1,0,1,0,0},
{0,1,1,0,0,0,1,0,1,0},
{0,1,1,1,1,1,0,0,1,0},
{0,0,1,0,1,1,1,1,0,1},
{0,1,1,0,0,0,1,1,1,1},
{0,0,1,0,0,1,0,1,0,1},
{1,0,1,0,1,1,0,0,0,0},
{0,0,0,0,1,1,0,0,0,1}};
	//{{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
	int n = numEnclaves(A);
	printf("N=%d\n", n);
	return n;
}
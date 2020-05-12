/*
 *	https://leetcode.com/problems/flood-fill/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
    
    
    void paint(std::vector<std::vector<int>>& image, int i, int j, int newColor, int oldColor) {
        int m = image.size();
        int n = (m) ? image[0].size() : 0;

        if(image[i][j] == oldColor) {
            image[i][j] = newColor;

            if((i > 0)) {//} and image[i-1][j] == oldColor) {
                paint(image, i-1, j, newColor, oldColor);
            }
            if((i < m-1)){//} and image[i+1][j] == oldColor) {
                paint(image, i+1, j, newColor, oldColor);
            }


            if((j > 0)){//} and image[i][j-1] == oldColor) {
                paint(image, i, j-1, newColor, oldColor);
            }
            if((j < n-1)){//} and image[i][j+1] == oldColor) {
                paint(image, i, j+1, newColor, oldColor);        
            }
        }
    }
    
    
    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc]; 
        if(newColor != oldColor)
            paint(image, sr, sc, newColor, image[sr][sc]);   
        return(image);
    }

    void dfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor) {
		printf("%d %d %d %d\n", row, col, oldColor, newColor);
        int nrows = image.size();
        int ncols = nrows ? image[0].size() : 0;
        if(row<0 or row>=nrows or col<0 or col>=ncols) return;
        if(image[row][col]==oldColor) image[row][col]=newColor;
        else return;
        dfs(image, row, col+1, oldColor, newColor), 
        dfs(image, row, col-1, oldColor, newColor), 
        dfs(image, row+1, col, oldColor, newColor), 
        dfs(image, row-1, col, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
int main() {
	std::vector<std::vector<int>> image = {{0,0,0},{0,1,1}};
	int sr = 1;
	int sc = 1;
	int newColor = 1;
	std::vector<std::vector<int>> image1 = floodFill(image, sr, sc, newColor);
	
	return 0;
}
/*
 *  Problem: https://leetcode.com/problems/flood-fill/
 *  Compile: g++ -o floodFill floodFill.cpp -std=c++11 -g -Wall -fsanitize=address && ./floodFill
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <deque>
#include <limits.h>

void print(std::vector<std::vector<int>> image) {
    for(auto i: image) {
        for(auto j: i) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
}

void paint(std::vector<std::vector<int>>& image, int i, int j, int newColor, int oldColor) {
    int m = image.size();
    int n = (m) ? image[0].size() : 0;
    printf("%d %d\n", i, j);
    if(image[i][j] == oldColor)
        image[i][j] = newColor;
    
    
    if((i > 0) and image[i-1][j] == oldColor) {
        paint(image, i-1, j, newColor, oldColor);
    }
    if((i < m-1) and image[i+1][j] == oldColor) {
        paint(image, i+1, j, newColor, oldColor);
    }
    
    
    if((j > 0) and image[i][j-1] == oldColor) {
        paint(image, i, j-1, newColor, oldColor);
    }
    if((j < n-1) and image[i][j+1] == oldColor) {
        paint(image, i, j+1, newColor, oldColor);        
    }
}


std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    paint(image, sr, sc, newColor, image[sr][sc]);    
    return(image);
}

int main(int argc, char **argv){
    //std::vector<std::vector<int>> image = {{0,0,0},{0,1,1}};
    
    
    std::vector<std::vector<int>> image = {{1,0,1,1},
                                           {0,1,1,0},
                                           {1,1,0,1},
                                           {1,1,0,1}};
                                         
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    print(image);
    
    std::vector<std::vector<int>> out = floodFill(image, sr, sc, newColor);
    print(out);
    
    
    return(0);
}
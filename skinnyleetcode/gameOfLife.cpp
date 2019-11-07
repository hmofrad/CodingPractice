    /*
 *  Problem: https://leetcode.com/problems/game-of-life/
 *  Compile: g++ -o gameOfLife gameOfLife.cpp -std=c++11 -fsanitize=address && ./gameOfLife
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>

void print(std::vector<std::vector<int>> board) {
    for(auto br: board) {
        for(auto bc: br) {
            printf("%d ", bc);
        }
        printf("\n");
    }
    printf("\n");
}

void printn(std::vector<int> neighborhood) {
    for(auto n: neighborhood) {
        printf("%d ", n);
    }
    printf("\n");
}

std::vector<int> get_neighborhood(std::vector<std::vector<int>> board, int i, int j) {
    std::vector<int> neighbors;
    int m = board.size();
    int n = (m) ? board[0].size() : 0;
    bool tf = false;
    for(int k = i-1; k <= i+1; k++) {
        if(k == i-1)
            tf = (k >= 0) ? true : false;
        if(k == i)
            tf = (k == i) ? true : false;
        if(k == i+1)
            tf = (k < m) ? true : false;
        if(tf) {
            if((j - 1) >= 0) {
                neighbors.push_back(board[k][j-1]);
            }
            neighbors.push_back(board[k][j]);
            if((j + 1) < n) {
                neighbors.push_back(board[k][j+1]);
            }
        }
        
    }
    
    /*
    if((i - 1) >= 0) {
        if((j - 1) >= 0) {
            neighbors.push_back(board[i-1][j-1]);
        }
        neighbors.push_back(board[i-1][j]);
        if((j + 1) < n) {
            neighbors.push_back(board[i-1][j+1]);
        }
    }
    if((j - 1) >= 0) {
        neighbors.push_back(board[i][j-1]);    
    }
    neighbors.push_back(board[i][j]);
    if((j + 1) < n) {
        neighbors.push_back(board[i][j+1]);
    }
    if((i + 1) < m) {
        if((j - 1) >= 0) {
            neighbors.push_back(board[i+1][j-1]);
        }
        neighbors.push_back(board[i+1][j]);
        if((j + 1) < n) {
            neighbors.push_back(board[i+1][j+1]);
        }
    }
    */
    return(neighbors);
}


void gameOfLife(std::vector<std::vector<int>>& board) {
    int m = board.size();
    int n = (m) ? board[0].size() : 0;
    std::vector<std::vector<int>> board1 = board;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            std::vector<int> neighbors = get_neighborhood(board, i, j);
            printf("%d %d: ", i, j);
            printn(neighbors);
            int s = std::accumulate(neighbors.begin(), neighbors.end(), 0);
            if(board[i][j]) {
                s -= 1;
                if(s < 2) board1[i][j] = 0;
                else if((s == 2) or (s == 3)) board1[i][j] = 1;
                else board1[i][j] = 0;//else if(s > 3) board1[i][j] = 0;
            }
            else {
                if(s == 3) board1[i][j] = 1;
            }
        }
    }
    board = board1;
    
}

int main(int argc, char **argv){
    std::vector<std::vector<int>> board = {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    print(board);
    gameOfLife(board);
    print(board);
    return(0);
}







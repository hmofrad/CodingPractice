/*
 *  Problem: exist
 *  Compile: g++ -o exist exist.cpp -std=c++11 && ./exist
 *  Execute: ./exist
 *  (c) Mohammad Mofrad, 2018
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

bool scanAdjacents(std::vector<std::vector<char>>& board, int i, int j, int up_idx, int right_idx, int down_idx, int left_idx, std::string word, int word_idx) {
    printf("b=%c w=%c up=%d right=%d down=%d left=%d\n", board[i][j], word[word_idx], up_idx, right_idx, down_idx, left_idx);
    int len = word.size();
    bool found = false;
    if(up_idx != -1) {
        if(board[i - up_idx][j] == word[word_idx]) {
            if((word_idx + 1) == len) {
                found = true;
            }
            else {
                ;
                // Giving up
                
            }
                
        } 
    }
        
    return(found);
}


bool exist(std::vector<std::vector<char>>& board, std::string word) {
    bool found = false;
    
    int m = board.size();
    int n = 0;
    if(m)
        n = board[0].size();
    int k = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == word[k]) {
                printf("%c == %c\n", board[i][j], word[k]);
                    int up_idx    = (i - 1 > 0) ? i - 1 : -1;
                    int right_idx = (j < n - 1) ? j + 1 : -1;
                    int down_idx  = (i < m - 1) ? i + 1 : -1;
                    int left_idx  = (j - 1 > 0) ? j - 1 : -1;
                    scanAdjacents(board, i, j, up_idx, right_idx, down_idx, left_idx, word, 1); 
            }
        }
    }
        
    
    return(found);
}

int main(int argc, char **argv) {
    
    int m = 3;
    int n = 4;
    std::vector<std::vector<char>> board;
    board.resize(m);
    for(int i = 0; i < m; i++)
        board[i].resize(n);
    board[0][0] = 'A';
    board[0][1] = 'B';
    board[0][2] = 'C';
    board[0][3] = 'E';
    board[1][0] = 'S';
    board[1][1] = 'F';
    board[1][2] = 'C';
    board[1][3] = 'S';
    board[2][0] = 'A';
    board[2][1] = 'D';
    board[2][2] = 'E';
    board[2][3] = 'E';
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    
    std::string word = "ABCCED";
    printf("exist(board, %s)=%d\n",word.c_str(), exist(board, word));
    
    return(0);
}
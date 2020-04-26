/*
 *  https://leetcode.com/problems/sliding-puzzle/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <deque>

using namespace std;


    std::set<std::string> visited;
    std::deque<std::string> boards;
    std::string board2string(vector<vector<int>> board) {
        std::string str;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                str.push_back(board[i][j]+'0');
            }
        }
        return str;
    }
    
void get_next(std::string board) {
        int len = board.length();
        int zero = -1;
        for(int i = 0; i < len; i++) if(board[i] == '0') {zero = i; break;}
        std::string t; 
        int prev = zero-1;
        int prev_row = prev/3;
        int next = zero+1;
        int next_row = next/3;
        int row = zero/3;
        
        if(prev>=0 and prev_row == row) {
            std::string t = board;
            std::swap(t[zero],t[prev]); 
            if(visited.count(t) == 0) boards.push_back(t);
        }
        
        if(next < len and next_row == row) {
            std::string t = board;
            std::swap(t[zero],t[next]); 
            if(visited.count(t) == 0) boards.push_back(t);
        }
        
        if(row == 0){
            int next_col = zero+3;
            std::string t = board;
            std::swap(t[zero],t[next_col]); 
            if(visited.count(t) == 0) boards.push_back(t);
        }
        if(row == 1) {
            int prev_col = zero-3;
            std::string t = board;
            std::swap(t[zero],t[prev_col]); 
            if(visited.count(t) == 0) boards.push_back(t);
        }
        
        /*
        switch(zero) {
            case 0: t = board;
                    std::swap(t[0],t[1]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[0],t[3]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    break;
            case 1: t = board;
                    std::swap(t[0],t[1]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[1],t[2]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[1],t[4]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    break;
            case 2: t = board; 
                    std::swap(t[2],t[5]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[1],t[2]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    break;
            case 3: t = board; 
                    std::swap(t[0],t[3]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[3],t[4]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    break;                
            case 4: t = board; 
                    std::swap(t[3],t[4]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[4],t[5]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[1],t[4]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    break;
            case 5: t = board; 
                    std::swap(t[2],t[5]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    t = board; 
                    std::swap(t[4],t[5]); 
                    if(visited.count(t) == 0) boards.push_back(t);
                    break;                  
              default: break;
        }
        */
    }

    
    int slidingPuzzle(vector<vector<int>>& board) {
        int nmoves = 0;
        boards.push_back(board2string(board));
        //std::string str = board2string(board);
        //printf("%s %s\n", boards.front().c_str(), str.c_str());
        int i = 0;
        while(not boards.empty()) {
            bool found = false;
            int size = boards.size();
            int s = 0;
            printf("1.%s %lu\n",  boards.front().c_str(), boards.size());
            while(s < size) {
                std::string front = boards.front();
                boards.pop_front();
                visited.insert(front);
                if(front == "123450") {return nmoves;}
                
                get_next(front);
                
                //printf("%s %s %s\n", boards[0].c_str(), boards[1].c_str(), boards[2].c_str());
                s++;
                //break;
                i++;
                //if(i == 20) break;
            }
            printf("2.%s %lu\n",  boards.front().c_str(), boards.size());
            nmoves++; 
            //if(not found) {nmoves++; break;}
            //break;
            //if(i == 20) break;
        }
        return -1;
    }


int main() {
    vector<vector<int>> board = {{1,2,3},{5,4,0}};
    int m = slidingPuzzle(board);
    printf("nmoves = %d\n", m);
    return 0;
}

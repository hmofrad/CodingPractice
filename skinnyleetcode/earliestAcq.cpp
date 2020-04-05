/*
 *  https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
    Compile and run: g++ -o earliestAcq earliestAcq.cpp && ./earliestAcq
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


   int ds_find(std::vector<int>& ds, int i) {
        return(ds[i] < 0 ? i : ds[i] = ds_find(ds, ds[i]));
    }
    
    int ds_union(std::vector<int>& ds, int i, int j) {
        i = ds_find(ds, i);
        j = ds_find(ds, j);
        
        if(i != j) {
            ds[i] += ds[j];
            ds[j] = i;
        }
        return -ds[i];
    }
    
    
    int earliestAcq1(std::vector<std::vector<int>>& logs, int N) {
        std::vector<int> ds(N, -1);
        std::sort(logs.begin(), logs.end());
        for(auto &log: logs) {
            if(ds_union(ds, log[1], log[2]) == N) return log[0];
        }
        return -1;
    }


std::vector<std::vector<bool>> grid;
int SZ;
std::vector<bool> visited1;
std::vector<bool> visited2;

bool checkAcq() {
    for(int i = 0; i < SZ; i++) {
        if(std::accumulate(grid[i].begin(), grid[i].end(), 0) == SZ)
            return(true);
    }
    return(false);    
}

void updateAcq(int row, int col) {
    printf("0. %d %d\n", row, col);
    if(grid[row][col] and grid[col][row]) return;
    
    grid[row][row] = true;
    grid[row][col] = true;
    grid[col][row] = true;
    grid[col][col] = true;
    
    printf("1. %d %d\n", row, col);
    for(int j = 0; j < SZ; j++) {
        if(grid[row][j] and not visited1[j]) {visited1[j] = true; updateAcq(j, col);}
        //if(grid[col][j] and j != row) updateAcq(j, row);
    }
    
    for(int j = 0; j < SZ; j++) {
        //if(grid[row][j] and j != col) updateAcq(j, col);
        if(grid[col][j]  and not visited2[j]) {visited2[j] = true; updateAcq(j, row);}
    }
    
    
    printf("2. %d %d\n", row, col);
    
    printf("3. %d %d\n", row, col);
    
    /*
    
    //if(grid[row][col]) return;
    //std::vector<int> todo_row;
    std::vector<int> stack;
    //stack.push_back(col);
    
    for(int j = 0; j < SZ; j++) {
        if(grid[row][j]) {
            stack.push_back(j);
            //updateAcq(col, row);
            //todo_row.push_back(j);
        }
    }
    
    
    
    while(not stack.empty()) {
        int top = stack.back();
        stack.pop_back();
        for(int j = 0; j < SZ; j++) {
            if(grid[top][j])
            stack.push_back(j);
        }
        if(not grid[top][col]) {
            grid[top][col] = true;
        }
    }
    
    
    for(int j = 0; j < SZ; j++) {
        if(grid[col][j]) {
            stack.push_back(j);
            //updateAcq(col, row);
            //todo_row.push_back(j);
        }
    }
    

    
    while(not stack.empty()) {
        int top = stack.back();
        stack.pop_back();
        for(int j = 0; j < SZ; j++) {
            if(grid[top][j])
            stack.push_back(j);
        }
        if(not grid[top][row]) {
            grid[top][row] = true;
        }
    }
    */
}

void printAcq() {
    for(int i = 0; i < SZ; i++) {
        for(int j = 0; j < SZ; j++) {
            printf("%d ", grid[i][j]==true);
        }
        printf("\n");
    }
    printf("\n");
}

void sortlogs(std::vector<std::vector<int>>& logs) {
    std::sort(logs.begin(), logs.end(), [](std::vector<int> a, std::vector<int> b) {
        return(a[0] < b[0]);
    });
}

int earliestAcq(std::vector<std::vector<int>>& logs, int N) {
    SZ = N;
    visited1.resize(N);
    visited2.resize(N);
    sortlogs(logs);
    //for(int i = 0; i < N; i++) people[i] = i;
    grid.resize(SZ);
    for(int i = 0; i < SZ; i++) grid[i].resize(SZ);
    int i = 0;
    int time = -1;
    for(std::vector<int> log: logs){
        int timestamp = log[0];
        int p1 = log[1];
        int p2 = log[2];
        printf("time=%d p1=%d p2=%d\n", timestamp, p1, p2);
        std::fill(visited1.begin(), visited1.end(), false);
        std::fill(visited2.begin(), visited2.end(), false);
        updateAcq(p1, p2);
        printAcq();
        if(checkAcq()) {time = timestamp; break;}
        
        //i++;
        //if(i == 3) break;
    }
    return(time);
}

int main() {
std::vector<std::vector<int>> logs = {{20190104,3,4},{20190101,0,1},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
int N = 6;
int r = earliestAcq(logs, N);
printf("%d\n", r);
return(0);
}
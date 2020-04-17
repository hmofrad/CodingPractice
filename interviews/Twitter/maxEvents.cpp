/*
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

void mySort(vector<int>& arrival, vector<int>& duration) {
    int sz = arrival.size();
    for(int i = 0; i < sz-1; i++) {
        for(int j = i+1; j < sz; j++) {
            if(arrival[i] > arrival[j]) {
                std::swap(arrival[i], arrival[j]);
                std::swap(duration[i], duration[j]);
            }
        }
    }
}

int dfs(vector<int> arrival, vector<int> duration, int index, int time, int numEvents) {
    printf("index=%d time=%d num=%d\n", index, time, numEvents);
    if(index == arrival.size()) return numEvents;
    
    int gain = 0;
    if(arrival[index] >= time) {        
        gain = dfs(arrival, duration, index+1, arrival[index]+duration[index], numEvents+1);
    }
    
    int next = dfs(arrival, duration, index+1, time, numEvents);
    return(max(gain, next));
    
}

int maxEvents(vector<int> arrival, vector<int> duration) {
    mySort(arrival, duration);
        for(auto a: arrival) printf("%d ", a); printf("\n");
    for(auto a: duration) printf("%d ", a); printf("\n");
    return(dfs(arrival, duration, 0, 0, 0));
}


int main() {
    vector<int> arrival = {1, 3, 5};
    vector<int> duration = {2, 2, 2};
    //vector<int> arrival = {1, 3, 3, 5, 7};
    //vector<int> duration = {2, 2, 1, 2, 1};
    //vector<int> arrival = {1, 3, 5, 7};
    //vector<int> duration = {2, 10, 2, 2};
    //vector<int> arrival = {250, 74, 659, 931, 273, 545, 879 };
    //vector<int> duration = {924, 710, 441, 166, 493, 43, 988};
    int r = maxEvents(arrival, duration);
    printf("\nRet=%d\n", r);
}
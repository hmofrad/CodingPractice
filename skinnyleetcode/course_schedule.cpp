/*
 *  Problem: course-schedule
 *  Compile: g++ -o course_schedule course_schedule.cpp -std=c++14 && ./course_schedule
 *  Execute: ./course_schedule
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
#include <queue>
#include <numeric>
#include <unordered_set>

void dfs(std::vector<std::vector<int>>& vec) {
    int src = vec[0][0];
    int dst = vec[0][1];
    for(int i = 1; i < vec.size(); i++){
        if(dst == vec[i][0]) {
                ;
        }
    }
    
}


bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    
    //dfs(prerequisites);
    bool ret = true;
    std::vector<bool> v(numCourses, false);
    //std::iota(v.begin(), v.end(), 0);
    printf("%d \n", numCourses);   
    
    std::sort(prerequisites.begin(), prerequisites.end(), [](auto& left, auto& right) {
        return left < right;
    });
    
    
    for(auto& p: prerequisites) {
        printf("[%d %d] ", p[0], p[1]);
        
    }
    printf("\n");
    
    
    for(int i = 0; i < prerequisites.size(); i++){
        int src = prerequisites[i][0];
        int dst = prerequisites[i][1];
        for(int j = i+1; j < prerequisites.size(); j++) {
            int src1 = prerequisites[j][0];
            int dst1 = prerequisites[j][1];
            if(dst == src1) {
                if(dst1 == src) {
                    ret = false;
                    break;
                }
                else {
                    src = 
                    dst = src1;
                }
            }
        }
        if(not ret) break;
        //if(not v[p[0]])
          ///  v[p[0]] = true;
        
        //;
        //pp.front(p[0]);
        //for(auto pp: p) {
          //  printf("%d ", pp);
            
        //}
        //printf("\n");
    }
    return(ret);
}

int main(int argc, char** argv) {
    int n = 3;
    std::vector<std::vector<int>> c = {{1,0}, {2, 1}, {0, 1}};
    bool r = canFinish(n, c);
    printf("canFinish()=%d\n", r);
    return(0);
}
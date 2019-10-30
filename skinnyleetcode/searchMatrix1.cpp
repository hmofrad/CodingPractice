    /*
 *  Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/
 *  Compile: g++ -o searchMatrix1 searchMatrix1.cpp -std=c++11 && ./searchMatrix1
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



bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    bool found = false;
    
    int m = matrix.size();
    int n = 0;
    if(m) {
        n = matrix[0].size();
    }

    int low = 0;
    int high = 0;
    int mid = 0;
    for(int i = 0; i < m; i++) {
        auto& vector = matrix[i];
        /*
        if(std::find(vector.begin(), vector.end(), target) != vector.end()) {
            found = true;
            break;
        }
        */
        
        low = 0;
        high = n - 1;//vector.size() - 1;
        while(low <= high) {
            //mid = low + (high - low) / 2;
            mid = (low + high) / 2;
            if(vector[mid] == target) {
                found = true;
                break;
            }
            else if(vector[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(found) {
            break;
        }  
        
    }
    return(found);
}
/*
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    bool found = false;
    
    int m = matrix.size();
    int n = 0;
    if(m) {
        n = matrix[0].size();
    }
    
    printf("sz=%d %d %d\n", m, n, matrix[0].empty());
    int i = 0;
    int j = 0;
    while((i < m) and (not matrix[i].empty())) {
        if((matrix[i][0] <= target) and (matrix[i][n-1] >= target)) {
            for(int k = 0; k < n; k++) {
                if(matrix[i][k] == target) {
                    found = true;
                    break;
                }
            }
        } 
        i++;
        if(found) {
            break;
        }
    }
    
    
    return(found);
}
*/
int main(int argc, char **argv){
    //std::vector<std::vector<int>> matrix = {{}};
    //std::vector<std::vector<int>> matrix = {{1,1}};
//    std::vector<std::vector<int>> matrix = {{1,   4,  7, 11, 15}, {2,   5,  8, 12, 19}, {3,   6,  9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    std::vector<std::vector<int>> matrix =     {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    for(auto& i: matrix) {
        for(auto& j: i) {
            printf("%d ", j); 
        }
        printf("\n");
    }

    int target = 5;
    bool found = searchMatrix(matrix, target);
    printf("searchMatrix ? %d\n", found);
    
    return(0);
}







/*
 *  Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 *  Compile: g++ -o kthSmallest_matrix kthSmallest_matrix.cpp -std=c++11  -g -Wall -fsanitize=address && ./kthSmallest_matrix
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

/*
int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    k--;
    uint32_t m = matrix.size();
    uint32_t n = matrix[0].size();
    int i = k/m;
    int j = k%n;
    printf("%d %d %d %d %d \n", m, n, i, j, k);
    return(matrix[i][j]);        
}
*/

int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    std::vector<int> smallests(matrix.size());
    std::vector<uint32_t> indices(matrix.size());
    int smallest = 0;
    
    for(uint32_t i = 0; i < matrix.size(); i++) {
        smallests[i] = matrix[i][0];
    }
    
    
    for(int32_t l = 0; l < k; l++) {
        //for(uint32_t i = 0; i < matrix.size(); i++) {
          //  if(indices[i] < matrix[0].size()) {
            //    smallests[i] = matrix[i][indices[i]];
            //}
        //}
        
        uint32_t j = 0;
        while(indices[j] >= matrix[0].size()) {
            j++;
        }
        smallest = smallests[j];
        int index = j;
        for(uint32_t i = j; i < smallests.size(); i++) {
            if(smallests[i] < smallest) {
                smallest = smallests[i];
                index = i;
            }
        }
        indices[index]++;
        if(indices[index] < matrix[0].size()) {
            smallests[index] = matrix[index][indices[index]];
        }
    }
    return(smallest);        
}


int main(int argc, char **argv){
    std::vector<std::vector<int>> matrix = {{ 1,  5,  9}, {10, 11, 13}, {12, 13, 15}}; //{{1,2},{1,3}};//
    int k = 8;
    int s = kthSmallest(matrix, k);
    printf("%d smallest = %d\n", k, s);
    return(0);
}







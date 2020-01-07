/*
 *  Problem: https://leetcode.com/problems/arithmetic-slices/
 *  Compile: g++ -o numberOfArithmeticSlices numberOfArithmeticSlices.cpp -std=c++11  -g -Wall -fsanitize=address && ./numberOfArithmeticSlices
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

int numberOfArithmeticSlices1(std::vector<int>& A) {
    int dp = 0;
    int sum = 0;
    for(uint32_t i = 2; i < A.size(); i++) {
        if((A[i] - A[i-1]) == (A[i-1] - A[i-2])) {
            dp++;
            sum += dp;
        }
        else {
            dp = 0;
        }
    }
    return(sum);
}


int numberOfArithmeticSlices(std::vector<int>& A) {
    if(A.size() < 3) {
        return(0);
    }
    /*
    int diff = A[1] - A[0];
    for(uint32_t i = 1; i < A.size(); i++) {
        if((A[i] - A[i-1]) != diff) {
            return(0);
        }
    }
    */
    int num = 0;
    
    for(uint32_t i = 3; i <= A.size(); i++) {
        //printf("%d\n", i);
        
        for(uint32_t j = 0; j <= (A.size() - i); j++) {
            bool tf = true;
            int diff = A[j+1] - A[j];    
            for(uint32_t k = j+1; k < i+j; k++) {
                if((A[k] - A[k-1]) != diff) {
                    tf = false;
                    break;
                }
                //printf("%d ", A[k]);
            }
            if(tf)
                num++;
        //    printf("\n"); 
        }
      //  printf("\n");
    }        
    
    //printf("%d\n", (A.size() - 3 + 1) * );

    return(num);
}    

int main(int argc, char **argv){
    std::vector<int> A = {1,2,3,8,9,10};
    int num = numberOfArithmeticSlices1(A);
    
    printf(">>>%d\n", num);
    return(0);
}







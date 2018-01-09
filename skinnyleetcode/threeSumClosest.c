/*  
 *  Problem: threeSumClosest (https://leetcode.com/problems/3sum-closest/description/)
 *  Compile: gcc -o threeSumClosest threeSumClosest.c -g -Wall -Werror 
 *  Execute: ./threeSumClosest
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_abs(int num) {
    int positiveNum = num;
    if(num < 0) {
        positiveNum = -num;
    }
    return(positiveNum);
}

// Slow solution
int threeSumClosest(int* nums, int numsSize, int target) {
    int closestSum = +214748364;
    int i = 0;
    int j = 0;
    int k = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int s = 0;
    for(i = 0; i < numsSize - 2; i++) {
        a = nums[i];
        for(j = i + 1; j < numsSize - 1; j++) {
            b = nums[j];
            for(k = j + 1; k < numsSize; k++) {
                c = nums[k];
                s = a + b + c;
                if(my_abs(s - target) < my_abs(closestSum - target)) {
                    closestSum = s;
                }
            }
        }
    }
    return(closestSum);
}




int main(int argc, char *argv[]) {
    int size = 4;
    int source[10]  = {0, 2, 1, -3};
    //int source[10]  = {-1, 2, 1, -4};
    //int source[10]  = {1, 1, 1, 0};
    
    int s = 0;
    for(s = 0; s < size; s++) {
        printf("%d ", source[s]);
    }
    printf("\n\n");
    
    int returnSize = 0;
    //int target = 1;
    int target = 1;
    int closestSum = threeSumClosest(source, size, target);
    printf("closestSum=%d\n", closestSum);
    
    
    return(0);
}
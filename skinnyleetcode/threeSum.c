/*  
 *  Problem: threeSum (https://leetcode.com/problems/3sum/description/)
 *  Compile: gcc -o threeSum threeSum.c -g -Wall -Werror 
 *  Execute: ./threeSum
 *  (c) Mohammad HMofrad, 2018
 *  (e) mohammad.hmofrad@pitt.edu
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* threeSort(int num1, int num2, int num3) {
    int *sortedArray = malloc(sizeof(int) * 3);
    int maxValue = num1;
    
    if((num1 <= num2) && (num2 <= num3)) {
        sortedArray[0] = num1;
        sortedArray[1] = num2;
        sortedArray[2] = num3;
    } else if ((num1 <= num3) && (num3 <= num2)) {
        sortedArray[0] = num1;
        sortedArray[1] = num3;
        sortedArray[2] = num2;
    }  else if ((num2 <= num1) && (num1 <= num3)) {
        sortedArray[0] = num2;
        sortedArray[1] = num1;
        sortedArray[2] = num3;
    }  else if ((num2 <= num3) && (num3 <= num1)) {
        sortedArray[0] = num2;
        sortedArray[1] = num3;
        sortedArray[2] = num1;
    }  else if ((num3 <= num1) && (num1 <= num2)) {
        sortedArray[0] = num3;
        sortedArray[1] = num1;
        sortedArray[2] = num2;
    }  else if ((num3 <= num2) && (num2 <= num1)) {
        sortedArray[0] = num3;
        sortedArray[1] = num2;
        sortedArray[2] = num1;
    }
    return(sortedArray);
}

int compare(int **array1, int array1Size, int *array2) {
    int new = 0;
    int i = 0;
    int j = 0;
    for(i = 0; i < array1Size; i++) {
        for(j = 0; j < 3; j++) {
            if(array1[i][j] == array2[j]) {
                new++;
            }
        }
        if(new == 3) {
            break;
        } else {
            new = 0;
        }
    }
    //printf("%d %d\n", new, array1Size);
    return(new);
}

  //str = (char *) realloc(str, 25);
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **ret = malloc(sizeof(int *));
    *returnSize = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    for(i = 0; i < numsSize - 2; i++) {
        for(j = i + 1; j < numsSize - 1; j++) {
            for(k = j + 1; k < numsSize; k++) {
                l = nums[i] + nums[j] + nums[k];
                if(!l) {
                    //printf("%d %d %d = %d\n", nums[i], nums[j], nums[k],l);
                    //ret[*returnSize] = malloc(sizeof(int) * 3);
                    //ret[*returnSize][0] = nums[i];
                    //ret[*returnSize][1] = nums[j];
                    //ret[*returnSize][2] = nums[k];
                    int *tempArray = threeSort(nums[i], nums[j], nums[k]);
                    if(!compare(ret, *returnSize, tempArray)) {
                        ret[*returnSize] = tempArray;
                        (*returnSize) = (*returnSize) + 1;
                        ret = realloc(ret, sizeof(int *) * ((*returnSize) + 1));
                    }
                    
                    //exit(0);
                }
            }
        }
    }
    return(ret);
}

int main(int argc, char *argv[]) {
    int size = 6;
    int source[10]  = {-1, 0, 1, 2, -1, -4};
    int s = 0;
    for(s = 0; s < size; s++) {
        printf("%d ", source[s]);
    }
    printf("\n");
    int returnSize = 0;
    int **returnedArray = threeSum(source, size, &returnSize);
    printf("%d\n", returnSize);
    
    int i = 0;
    int j = 0;
    for(i = 0; i < returnSize; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", returnedArray[i][j]);
        }
        printf("\n");
    }
    
    return(0);
}
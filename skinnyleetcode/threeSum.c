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
 
 
void insertionSort(int *nums, int numsSize) {
    int i = 0;
    int j = 0;
    int value = 0;
    for(i = 1; i < numsSize; i++) {
        value = nums[i];
        j = i;
        while((j > 0) && (nums[j-1] > value)) {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = value;
    }
} 

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

/*
// Slow solution
int** threeSum(int* nums, int numsSize, int* returnSize) {
    insertionSort(nums, numsSize);
    int size = 1;
    int **ret = malloc(sizeof(int *) * size);
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
                    int *tempArray = threeSort(nums[i], nums[j], nums[k]);
                    if(!compare(ret, *returnSize, tempArray)) {
                        ret[*returnSize] = tempArray;
                        *returnSize = *returnSize + 1;
                    }
                    if(*returnSize == size) {
                        size *= 2;
                        ret = realloc(ret, sizeof(int *) * size);
                    }
                }
            }
        }
    }
    return(ret);
}
*/

// Fast solution
int** threeSum(int* nums, int numsSize, int* returnSize) {
    insertionSort(nums, numsSize);
    int size = 1;
    int **ret = malloc(sizeof(int *) * size);
    *returnSize = 0;
    int *tempArray = NULL;
    
    int a = 0;
    int b = 0;
    int c = 0;
    int i = 0;
    int left = 0;
    int right =0;
    for(i = 0; i < numsSize - 2; i++) {
        a = nums[i]; 
        left = i + 1;
        right = numsSize - 1;
        while(left < right) {
            b = nums[left];
            c = nums[right];
            if(!(a + b + c)) {
                printf("%d %d %d %d %d %d\n", i, left, right, a, b, c);
                tempArray = malloc(sizeof(int) * 3);
                tempArray[0] = a;
                tempArray[1] = b;
                tempArray[2] = c;
                if(!compare(ret, *returnSize, tempArray)) {
                    ret[*returnSize] = tempArray;
                    *returnSize = *returnSize + 1;
                    if(*returnSize == size) {
                        size *= 2;
                        ret = realloc(ret, sizeof(int *) * size);
                    }
                }
                if(nums[left + 1] == b) {
                    left++;
                } else {
                    right--;
                }
            } else if((a + b + c) > 0) {
                right--;
            } else { // (a + b + c) < 0
                left++;
            }
            
        }
        
    }
    return(ret);
}


int main(int argc, char *argv[]) {
    int size = 7;
    int source[10]  = {-1, 0, 1, 2, -1, -4, 3};
    
    //insertionSort(source, size);
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
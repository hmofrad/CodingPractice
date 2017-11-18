/*
 *  Problem: Median of Two Sorted Arrays (https://leetcode.com/problems/median-of-two-sorted-arrays/description/)
 *  Compile: gcc -o findMedianSortedArrays findMedianSortedArrays.c -g -Wall -Werror 
 *  Execute: ./findMedianSortedArrays
 *  (c) Mohammad HMofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu       
 */
 
 
 #include <stdio.h>
 #include <stdlib.h>
 
 
 double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0 ;
    int j = 0;
    double median = 0;
    double median0 = 0;
    int medianIndex = -1;

    medianIndex = (int) (nums1Size + nums2Size) / 2;
    i = 0;
    j = 0;
    while((i + j) <= medianIndex) {
        median0 = median;
        if(nums1[i] > nums2[j]) {
            if(j < nums2Size) {
                median = (double) nums2[j];
                j++; // Median belongs to nums1
            } else {
                median = (double) nums1[i];
                i++; // Median belongs to nums2
            }
        } else {
            if(i < nums1Size) {
                median = (double) nums1[i];
                i++; // Median belongs to nums2
            } else {
                median = (double) nums2[j];
                j++; // Median belongs to nums2                
            }
        }
        //printf("%d ", (int) median);
    }
    //printf("\n");
    
    if(((nums1Size + nums2Size) % 2) == 0) {
        median = (double) (median0 + median) / 2; // Even size
    }
    return(median);
} 
 
 int main (int argc, char* argv[]) {
    int nums1Size = 4; 
    int nums1[nums1Size];
    nums1[0] = 1;
    nums1[1] = 3;
    nums1[2] = 8;
    nums1[3] = 11;
    
    int nums2Size = 5;
    int nums2[nums2Size];
    nums2[0] = 4;
    nums2[1] = 6;
    nums2[2] = 7;
    nums2[3] = 9;
    nums2[3] = 10;
    
    int i = 0;
    printf("nums1: "); 
    for(i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n"); 

    
    printf("nums2: "); 
    for(i = 0; i < nums2Size; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n"); 
    
    
    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size); 
     
    printf("%f \n", median); 
    return(0);
 }
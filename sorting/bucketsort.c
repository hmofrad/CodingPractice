/*
 * Bucket sort algorithm
 * For more reading go to "https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html"
 * (c) Mohammad H. Mofrad, 2016
 * (e) hasanzadeh@cs.pitt.edu
 * Compile and run using "gcc -o bucketsort bucketsort.c && ./bucketsort" 
 */

#include <stdio.h>
#include <stdlib.h>
#define length(x) (sizeof(x)/sizeof(x[0])) //Only compatible with arrays

void bucketsort(int arr[], int len)
{
   int i;
   int max = 0;
   for(i = 0; i < len; i++)
   {
      if(arr[i] > max)
      {
         max = arr[i];
      }
   }
   printf("Max: %d\n", max);

   int bucket[max+1];
   for(i = 0; i < max+1; i++)
   {
      bucket[i] = 0;
      printf("bucket[%2d] = %2d\n", i, bucket[i]);
   }

   for(i = 0; i < len; i++)
   {
      bucket[arr[i]] += 1;
   }
   
   int j = 0;
   for(i = 0; i < max + 1; i++)
   {
      printf("bucket[%2d] = %2d\n", i, bucket[i]);
      if(bucket[i])
      {
         arr[j] = i;
         j++;
      }
   }
}


int main(int argc, char *argv[])
{
   
   int arr[] = {3, 11, 2, 9, 1, 5, 11};
   int arr_s = length(arr);
   int i;
   printf("input: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   bucketsort(arr, arr_s);

   printf("output: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return(0);
}

/*
 * Insertion sort algorithm
 * For more reading go to "https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html"
 * (c) Mohammad H. Mofrad, 2016
 * (e) hasanzadeh@cs.pitt.edu
 * Compile and run using "gcc -o insertionsort insertionsort.c && ./insertionsort"
 */

#include <stdio.h>
#include <stdlib.h>

#define length(x) (sizeof(x) / sizeof(x[0])) // Only works with arrays

void insertionsort(int arr[], int len)
{
   int i;
   int j;
   int index;

   for(i = 1; i < len; i++)
   {
      index = arr[i];
      j = i;
      while(j > 0 && index < arr[j-1])
      {
         arr[j] = arr[j-1];
         j--; 
      }
      arr[j] = index;
   }
}

int main(int argc, char *argv[])
{
   int arr[] = {29, 20, 73, 34, 64};
   int arr_s = length(arr);
   int i;

   printf("input: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   insertionsort(arr, arr_s);

   printf("output: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return(0);
}

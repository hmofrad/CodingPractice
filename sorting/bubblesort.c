/*
 * Bubble sort algorithm
 * For more reading go to "https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html"
 * (c) Mohammad H. Mofrad, 2016
 * (e) hasanzadeh@cs.pitt.edu
 * Compile and run using "gcc -o bubblesort bubblesort.c && ./bubblesort"
 */

#include <stdio.h>
#include <stdlib.h>

#define length(x) (sizeof(x) / sizeof(x[0])) // Only works with arrays

void bubblesort(int arr[], int len)
{

   int i;
   int j;
   int tmp;
   for(i = len - 1; i >= 0; i--)
   {
      for(j = 0; j < i; j++)
      {
         if(arr[j] > arr[j+1])
         {
            tmp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = tmp;
         }
      }
      for(j = 0; j < len; j++)
      {
         printf("%d ", arr[j]);
      }
      printf("\n");
   }
}


int main(int argc, char *argv[])
{
   int arr[] = {7, 5, 2, 4, 3, 9};
   int arr_s = length(arr);

   int i;
   printf("input: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   bubblesort(arr, arr_s);  

   printf("output: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return(0);
}

/*
 * Selection sort algorithm
 * For more reading go to "https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html"
 * (c) Mohammad H. Mofrad, 2016
 * (e) hasanzadeh@cs.pitt.edu
 * Compile and run using "gcc -o selectionsort selectionsort.c && ./selectionsort"
 */

#include <stdio.h>
#include <stdlib.h>

#define length(x) (sizeof(x) / sizeof(x[0])) // Only works with arrays

void selectionsort(int arr[], int len)
{
   int i;
   int j;
   int min;
   int tmp;
   for(i = 0; i < len - 1; i++)
   {
      min = i;
      for(j = i+1; j < len; j++)
      {
          if(arr[j] < arr[min])
          {
             min = j;
          }
      }
      tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
   }
}


int main(int argc, char *argv[])
{
   int arr[] = {29, 64, 73, 34, 20};
   int arr_s = length(arr);
   int i;

   printf("input: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   selectionsort(arr, arr_s);

   printf("output: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
   return(0);
}

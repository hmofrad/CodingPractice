/*
 * For more reading go to "https://interactivepython.org/runestone/static/pythonds/SortSearch/TheQuickSort.html"
 * Originally copied from "http://quiz.geeksforgeeks.org/quick-sort/"
 * (c) Mohammad H. Mofrad, 2016
 * (e) hasanzadeh@cs.pitt.edu
 * Compile and run using "gcc -o mergesort1 mergesort1.c && ./mergesort1"
 */

#include <stdio.h>
#include <stdlib.h>

#define length(x) (sizeof(x)/sizeof(x[0])) // Only works with arrays

void swap(int *a, int *b)
{
   int t = *a;
   *a = *b;
   *b = t;
}

int partition(int arr[], int low, int high)
{
   int pivot = arr[high];
   int i = low - 1;
   int j = low;
   for(j = low; j <= high - 1; j++)
   {
      if(arr[j] <= pivot)
      {
         i++;
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i+1], &arr[high]);
   return(i + 1);
}


void quicksort(int arr[], int low, int high)
{
   if(low < high)
   {
      int pivot = partition(arr, low, high);
      quicksort(arr, low, pivot - 1);
      quicksort(arr, pivot + 1, high);
   }
}


int main(int *argc, char *argv[])
{

   int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
   int arr_s = length(arr);
   int i;

   printf("Input: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   quicksort(arr, 0, arr_s - 1);

   printf("Output: ");
   for(i = 0; i < arr_s; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return(0);
}

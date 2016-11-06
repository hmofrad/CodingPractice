/*
 * Merge sort algorithm
 * Originally copied from "http://quiz.geeksforgeeks.org/merge-sort/"
 * (c) Mohammad H. Mofrad, 2016
 * (e) hasanzadeh@cs.pitt.edu
 * Compile and run using "gcc -o mergesort mergesort.c && ./mergesort"
 */

#include <stdio.h>
#include <stdlib.h>

#define length(x) (sizeof(x)/sizeof(x[0])) //Only compatible with arrays

void merge(int arr[], int l, int m, int r)
{
   printf("Left (%d), Middle (%d), Right (%d)\n",l, m, r);
   int i = 0;
   int j = 0;
   int k = 0;
   
   int n1 = m - l + 1;
   int n2 = r - m;
   printf("N1 (%d), N2 (%d)\n", n1, n2);

   int L[n1];
   int R[n2];
   
   for(i = 0; i < n1; i++)
   {
      L[i] = arr[l + i];
   }
   for(j = 0; j < n2; j++)
   {
      R[j] = arr[m + 1 + j];
   }

   i = 0;
   j = 0;
   k = l;
   while(i < n1 && j < n2)
   {
      if(L[i] <= R[j])
      {
         arr[k] = L[i];
         i++;
      }
      else
      {
         arr[k] = R[j];
         j++;
      }
      k++;
   }
   
   while(i < n1)
   {
      arr[k] = L[i];
      i++;
      k++;
   }
   
   while(j < n2)
   {
      arr[k] = R[j];
      j++;
      k++;
   }



}

void merge_sort(int arr[], int l, int r)
{
   if(l < r)
   {
      int m = l + (r - l) / 2;
      printf("[%d %d][%d %d]\n", l, m, m+1, r);
      merge_sort(arr, l, m);
      merge_sort(arr, m + 1, r);
      printf("Merge \n");
      merge(arr, l, m, r);
   }
}


int main(int argc, char *argv[])
{
   int arr[] = {12, 11, 13, 4, 6, 7};
   int arr_s = length(arr);
   int i = 0;
   printf("input: ");
   for(i = 0; i < arr_s; i++)
   {
       printf("%d ", arr[i]);
   }
   printf("\n");

   merge_sort(arr, 0, arr_s - 1);
   
   printf("output: ");
   for(i = 0; i < arr_s; i++)
   {
       printf("%d ", arr[i]);
   }
   printf("\n");


   return(0);
}

/*
  * Reserve String implementation in C
  * (c) Mohammad H. Mofrad
  * (e) hasanzadeh@cs.pitt.edu
  * Compile and run using "gcc -o ReverseString ReverseString.c && ./ReverseString"
   */  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[], int left, int rigth);
void replace(char str[], int left, int middle, int right);

int main(int argc, char *argv[])
{
   char str[100] = "Hello,World!";
   int length = strlen(str);
   printf("Input Raw String: %s\n", str);
   reverse(str, 0, length - 1);
   printf("Output Reversed String: %s\n", str);
   return(0);
}

void replace(char str[], int left, int middle, int right)
{
   printf("\nInput String: %s\n", str);
   printf("Left Substring Index (%d), Middle Substring Index (%d), Right Substring Index (%d)\n",left, middle, right);
   printf("Left Substring Character (%c), Middle Substring Character (%c), Right Substring Character (%c)\n",str[left], str[middle], str[right]);
   int i = 0;
   int j = 0;
   int k = 0;

   int n1 = middle - left + 1;
   int n2 = right - middle;
   printf("Left Substring length (%d), Right substring length (%d)\n", n1, n2);

   char L[n1+1];
   memset(L,'\0',n1+1);
   char R[n2+1];
   memset(R,'\0',n2+1);

   i = 0;
   j = 0;
   k = left;
   for(i = 0; i < n1; i++)
   {
      L[i] = str[left + i];
   }
   for(j = 0; j < n2; j++)
   {
      R[j] = str[middle + 1 + j];
   }
   printf("Left Substring (%s), Right Substring (%s)\n", L, R);

   i = 0;
   j = 0;
   k = left;

   while(i < n2)
   {
      str[k] = R[i];
      i++;
      k++;
   }
      while(j < n1)
   {
      str[k] = L[j];
      j++;
      k++;
   }
   printf("Output String: %s\n", str);
}

void reverse(char str[], int left, int right)
{
    int middle = left + (right - left) / 2;
    printf("%d, %d, %d\n", left, middle, right);
    if(left < right)
    {
       reverse(str, left, middle);
       reverse(str, middle+1, right);
       replace(str, left, middle, right);
    }
}

/*
 *  Problem: Search insert position ()
 *  Compile: g++ -o searchInsert searchInsert.cpp && ./searchInsert
 *  Execute: ./searchInsert
 *  (c) Mohammad Mofrad, 2018
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>


int main(int argc, char **argv)
{
    int n = 4;
    int arr[] = {1, 3, 5 ,6};
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    int num = 7;
    int pos = -1;
    for(int i = 0; i < n; i++)
    {
        if((arr[i] == num) or (arr[i] > num))
        {
            pos = i;
            break;
        }
    }
    if(pos = -1)
        pos = n;
    printf("Position=%d\n", pos);
    return(0);
}
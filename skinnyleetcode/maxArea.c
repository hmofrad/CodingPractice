/*
 *  Problem: maxArea (https://leetcode.com/problems/container-with-most-water/description/)
 *  Compile: gcc -o maxArea maxArea.c -g -Wall -Werror 
 *  Execute: ./maxArea
 *  (c) Mohammad HMofrad, 2017
 *  (e) mohammad.hmofrad@pitt.edu
 */


#include <stdio.h>
#include <stdlib.h>

int area(int width, int height) {
    return(width * height);
}

int min(int h1, int h2) {
    int min = 0;
    if(h1 > h2) {
        min = h2;
    } else {
        min = h1;
    }
    return(min);
}

int maxArea(int* height, int heightSize) {
    int x0 = 0;
    int y0 = 0;
    int x1 = 0;
    int y1 = 0;
    
    int x01 = 0;
    int y01 = 0;
    int x11 = 0;
    int y11 = 0;
    
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    for(i = 0; i < heightSize; i++) {
        j = i + 1;
        x0 = j;
        y0 = 0;
        x1 = j;
        y1 = height[i];
        printf("(%d, %d), (%d, %d)\n", x0, y0, x1, y1);
        for(k = i + 1; k < heightSize; k++) {
            l = k + 1;
            x01 = l;
            y01 = 0;
            x11 = l;
            y11 = height[k];
            int w = x11 - x1;
            int h = min(y1 , y11);
            int s = area(w, h);
            if(s > m) {
                m = s;
            }
            printf("    (%d, %d), (%d, %d) = (%dx%d) = %d\n", x01, y01, x11, y11, w, h, s);
        }
        printf("\n");
    }
    
    return(m);
}

int main(int argc, char *argv[]) {
    int height[3];
    height[0] = 2;
    height[1] = 5;
    height[2] = 3;
    int heightSize = sizeof(height)/sizeof(height[0]);
    int r = maxArea(height, heightSize);
    printf("maxArea(...)=%d\n", r);
    return(0);
}

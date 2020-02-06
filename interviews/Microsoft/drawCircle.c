/*
 *  Problem: https://www.geeksforgeeks.org/draw-circle-without-floating-point-arithmetic/
 *  Given a radius of a circle, draw the circle without using floating point arithmetic.
 *  Compile: gcc -o drawCircle drawCircle.c -g -Wall -fsanitize=address && ./drawCircle    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

void draw_circle(int radius) {
    
    for(int i = 0; i < (2*radius) + 1; i++) {
        for(int j = 0; j < (2*radius) + 1; j++) {  
            int x = i-radius;
            int y = j-radius;
            if(((x*x) + (y*y)) < (radius * radius)) {
                printf(".");
            }
            else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}



int main(int argc, char **argv){
    int radius = 8;
    draw_circle(radius);
    return(0);
}

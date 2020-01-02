/*
 *  Cracking the coding interview: Problem 5.8: Implement a draw line for a monochrome screen
 *  Compile & run: g++ -o monochromeScreen monochromeScreen.cpp -g -Wall -std=c++11 -fsanitize=address && ./monochromeScreen
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <string.h>

unsigned char* screen;
void print(uint32_t height, uint32_t width);

bool get_pixel(uint32_t height, uint32_t width, std::pair<uint32_t, uint32_t> pixel) {
    uint32_t pixel_byte = (pixel.first * (width/8)) + (pixel.second/8);
    uint32_t pixel_bit = pixel.second % 8;
    unsigned char mask = 1 << pixel_bit;
    return((screen[pixel_byte] & mask) != 0);
}

void set_pixel(uint32_t height, uint32_t width, std::pair<uint32_t, uint32_t> pixel, int value) {
    uint32_t pixel_byte = (pixel.first * (width/8)) + (pixel.second/8);
    uint32_t pixel_bit = pixel.second % 8;
    unsigned char mask = 1 << pixel_bit;
    screen[pixel_byte] |= mask;
}

void print(uint32_t height, uint32_t width) {
    for(uint32_t i = 0; i < height; i++) {
        for(uint32_t j = 0; j < width; j++) {
            printf("%d ", get_pixel(height, width, {i,j}));
        }
        printf("\n");
    }
    printf("\n");
}

void drawHorizontalLine(uint32_t height, uint32_t width, uint32_t x1, uint32_t x2, uint32_t y) {
    
    for(uint32_t j = x1; j <= x2; j++) {
        set_pixel(height, width, {y,j}, true);
    }
}

int main(int argc, char** argv) {
    uint32_t height = 32;
    uint32_t width  = 64;
    uint32_t area_in_bytes = (height * width)/ 8;
    screen = (unsigned char*) malloc(area_in_bytes);
    memset(screen, 0, area_in_bytes);
    drawHorizontalLine(height, width, 10, 45, 20);
    //print1(height, width);
    print(height, width);
    
    free(screen);
    return(0);
}
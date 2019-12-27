/*
  * Cracking the coding interview: Problem 1.6: Rotate an image 90 degree
  * Compile and run:  g++ -o rotate rotate.cpp -g -Wall -std=c++11 -fsanitize=address && ./rotate
  * (c) Mohammad Hasanzadeh mofrad, 2019
  * (e) m.hasanzadeh.mofrad@gmail.com
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
void rotate(std::vector<std::vector<char>>& image) {
    uint32_t nrows = image.size();
    uint32_t ncols = image[0].size();
    for(uint32_t i = 0; i < nrows; i++) {
        for(uint32_t j = i; j < ncols; j++) {    
            std::swap(image[i][j], image[j][i]);
        }
    }
}

int main(int argc, char* argv[]) {
    std::vector<std::vector<char>> image = {{1,1,1,1},
                                            {0,0,0,1},
                                            {0,0,0,1},
                                            {0,0,0,1}};
                                            //{0,0,0,1}};
    
    for(auto row: image) {
        for(auto col: row) {
            printf("%d ", col);
        }
        printf("\n");
    }
    printf("\n");
    
    rotate(image);
    
    printf("\n");
    for(auto row: image) {
        for(auto col: row) {
            printf("%d ", col);
        }
        printf("\n");
    }
    return(0);
}
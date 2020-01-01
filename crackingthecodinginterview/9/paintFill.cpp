/*
 *  Cracking the coding interview: Problem 9.7: Given a 2D array, a point, and a color, fill in the surronding
 *  Compile & run: g++ -o paintFill paintFill.cpp -g -Wall -std=c++11 -fsanitize=address  && ./paintFill
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>

void print(std::vector<std::vector<int>> screen) {
    for(auto r: screen) {
        for(auto c: r) {
            printf("%d ", c);
        }
        printf("\n");
    }
    printf("\n");
}

void paintFill(std::vector<std::vector<int>>& screen, std::pair<int32_t, int32_t> point, int color) {
    int32_t m = (int32_t)(screen.size()-1);
    int32_t n = 0;
    if(m) {
        n = (int32_t)(screen[0].size()-1);
    }
    
    if((((point.first >= 0) and (point.first <=  m)) and ((point.second >= 0) and (point.second <= n))) and (screen[point.first][point.second] != color)) {
        printf("%d %d\n", point.first, point.second);
        screen[point.first][point.second] = color;
        paintFill(screen, {(point.first)-1, point.second}, color);
        paintFill(screen, {(point.first)+1, point.second}, color);
        paintFill(screen, {(point.first), (point.second)-1}, color);
        paintFill(screen, {(point.first), (point.second)+1}, color);
    }
    else {
        return;
    }
    //}
    
}


int main(int argc, char** argv) {
    int n = 5;
    std::vector<std::vector<int>> screen(n, std::vector<int>(n));
    std::pair<int32_t, int32_t> point(2,2);
    print(screen);
    int color = 1;
    paintFill(screen, point, color);
    print(screen);
    
    return(0);
}
/*
 *  Cracking the coding interview: Problem 9.10: Stack boxes atop each other
 *  Compile & run: g++ -o boxes boxes.cpp -g -Wall -std=c++11 -fsanitize=address  && ./boxes
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>

struct Box {
    uint32_t width;
    uint32_t height;
    uint32_t depth;
};


bool canBeAbove(const struct Box box1, const struct Box box2) {
        
        return((box1.width >= box2.width) and 
               (box1.height >= box2.height) and 
               (box1.depth >= box2.depth));
    }
    

std::vector<struct Box> stack(std::vector<struct Box> boxes, struct Box bottomBox) {
    int max_height = 0;
    std::vector<struct Box> maxStack;
    for(uint32_t i = 0; i < boxes.size(); i++) {
        printf("%d %lu\n", i, boxes.size());
        if(canBeAbove(boxes[i], bottomBox)) {
            std::vector<struct Box> newStack = stack(boxes, boxes[i]);
            int new_height = 0;
            for(auto s: newStack) {
                new_height += s.height;
            }
            if(new_height > max_height) {
                maxStack = newStack;
                max_height = new_height;
            }
        }
    }
    
    
    if(bottomBox.height != 0) {
        maxStack.push_back(bottomBox);
    }
    
    return(maxStack);
}


int main(int argc, char** argv) {
    std::vector<struct Box> boxes = {{10, 5, 7,}, {100, 4, 8}, {4, 2, 7}, {34, 89, 12}, {150, 20, 34}, {300, 230, 560}};
    struct Box box = {0,0,0};
    //printf("%d\n", std::tuple_size<uint32_t>::value);
    std::vector<struct Box> bb = stack(boxes, box);
    for(auto b: bb) {
        printf("%d %d %d\n", b.width, b.height, b.depth);
    }
    
    return(0);
}
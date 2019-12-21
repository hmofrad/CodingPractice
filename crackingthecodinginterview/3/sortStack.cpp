/*
 * Cracking the coding interview: Problem 3.6: Sort an stack in an ascending order (largest at top) using another stack
 * Compile and run: g++ -o sortStack sortStack.cpp -g -Wall -std=c++11 -fsanitize=address  && ./sortStack
 * (c) Mohammad Hasanzadeh Mofrad, 2019
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


bool isempty(std::vector<int> top) {
    return(top.empty());
}

void push(std::vector<int>& top, int value) {
    top.push_back(value);
}

int pop(std::vector<int>& top) {
    if(!isempty(top)) {
        int value = top.back();
        top.pop_back();
        return(value);
    }
    else {
        return(-1);
    }
}

int peek(std::vector<int> top) {
    if(!isempty(top)) {
        return(top.back());
    }
    else {
        return(-1);
    }
}

void print(std::vector<int> top) {
    for(int i = top.size()-1; i >= 0; i--) {
        printf("%d ", top[i]);
    }
    printf("\n");
}

void sort(std::vector<int>& top) {
    std::vector<int> helper;
    //push(helper, pop(top));
    int i = 0;
    while(!isempty(top)) {
        //print(top);
        //print(helper);
        if(isempty(helper)) {
            push(helper, pop(top));
        }
        else {
            if(peek(helper) > peek(top)) {
                int v = pop(top);
                int w = peek(helper);
                while(!isempty(helper) and peek(helper) > v) {
                    push(top, pop(helper));
                }
                push(helper, v);
                while(!isempty(top) and peek(top) != w) {
                    push(helper, pop(top));
                }
                //push(helper, pop(top));
            }
            else {
                push(helper, pop(top));
            }
        }
        print(top);
        print(helper);
        printf("%d\n",i);
        i++;
    }
    print(top);
    print(helper);
}


void sort_s(std::vector<int>& top) {
    std::vector<int> helper;
    while(!isempty(top)) {
        int v = pop(top);
        while(!isempty(helper) and peek(helper) > v) {
            push(top, pop(helper));
        }
        push(helper, v);
        print(top);
        print(helper);
    }
    top = helper;
}



int main(int argc, char** argv) {
    std::vector<int> stack0 = {0, 10, 3, 20, 76, 100, 30, 240, 2, 7, 34, 2, 98};   
    
    
    /*
    for(int i = 5; i >= 0; i--) {
        push(stack0, i);
    }
    */
    
    
    
    //print(stack0);
    //sort(stack0);
    sort(stack0);
    print(stack0);

    return(0);
}
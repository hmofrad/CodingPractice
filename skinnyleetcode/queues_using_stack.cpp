    /*
 *  Problem: https://leetcode.com/problems/implement-queue-using-stacks/
 *  Compile: g++ -o queues_using_stack queues_using_stack.cpp -std=c++11 && ./queues_using_stack
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <stack>

class MyStack {
public:
    std::stack<int> stack;
    int peek_v = 0;
    MyStack() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(stack.empty()) {
            peek_v = x;
        }
        stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = 0;
        if(stack.empty()) {
            peek_v = 0;
            return(v);
        }
        
        std::stack<int> tmp;
        while(!stack.empty()) {
            tmp.push(stack.top());
            stack.pop();
        }
        
        v = tmp.top();
        tmp.pop();
        
        if(!tmp.empty()) {
            peek_v = tmp.top();
        }
        else {
            peek_v = 0;
        }
        
        while(!tmp.empty()) {
            stack.push(tmp.top());
            tmp.pop();
        }
        
        return(v);

    }
    
    /** Get the front element. */
    int peek() {
        return(peek_v);
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return(stack.empty());
        
    }
};


int main(int argc, char **argv){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    
    
    printf("%d %d %d\n", param_2, param_3, param_4);
    
    delete obj;
    return(0);
}







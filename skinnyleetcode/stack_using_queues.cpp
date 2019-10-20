    /*
 *  Problem: https://leetcode.com/problems/implement-stack-using-queues/
 *  Compile: g++ -o stack_using_queues stack_using_queues.cpp -std=c++11 && ./stack_using_queues
 *  Execute: ./stack_using_queues
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
#include <queue>

class MyStack {
public:
   std::deque<int> queue;

  MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = queue.back();
        queue.pop_back();
        return(v);
    }
    
    /** Get the top element. */
    int top() {
        int v = queue.back();
        return(v);
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return(queue.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 
 */

int main(int argc, char **argv){
    MyStack* obj = new MyStack();
    
    obj->push(1);
    obj->push(2); 
    int param_2 = obj->top();
    int param_3 = obj->pop();
    bool param_4 = obj->empty();
    int param_5 = obj->top();
    printf("%d %d %d\n", param_2, param_3, param_5);
    
    delete obj;
    return(0);
}







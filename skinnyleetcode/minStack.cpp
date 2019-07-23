/*
 *  URL: https://leetcode.com/problems/min-stack/
 *  Compile & Execute: g++ -o minStack minStack.cpp -std=c++11 && ./minStack
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
 
struct StackNode {
    int value;
    struct StackNode *prev;
    struct StackNode *next;
};    
 
class MinStack {
public:
    
    struct StackNode *head;
    struct StackNode *min;
    int min_val = 2147483647;
    
    MinStack() {
        head = nullptr;
        min = nullptr;
    }
    
    
    void push(int x) {
        if(head) {
            //printf("Head is here\n");
            head->next = new StackNode();
            head->next->prev = head;
            head->next->next = nullptr;
            head->next->value = x;
            head = head->next;
            updateMin(x, head);
        }
        else {
            head = new StackNode();
            head->value = x;
            head->prev = nullptr;
            head->next = nullptr;
            //min = new StackNode();
            updateMin(x, head);
        }
    }
    void traverse() {
        struct StackNode *curr = head;
        while(curr) {
            printf("%d ", curr->value);
            curr = curr->prev;
        }
        printf("\n");
    }
    
    void pop() {
        //struct StackNode *curr = head;
        if(head->prev) {
            //printf("[%p %p %p] %d\n",head->prev, head, head->next, head->value);
            bool tf = (min == head) ? true : false;
            head = head->prev;
            delete head->next;
            head->next = nullptr;
            if(tf) {
                updateMin();
            }
            //printf("[%p %p %p] %d\n",head->prev, head, head->next, head->value);
        }
        else {
            delete head;
            head = nullptr;
            min_val = 2147483647;
            min = nullptr;
        }
    }
    
    int top() {
        int top_val = 0;
        if(head) {
            top_val = head->value;
        }
        else {
            top_val = 0;
        }
        return(top_val);
    }
    
    void updateMin(int x, struct StackNode *node) {
        if(x < min_val) {
            min_val = x;
            min = node;
        }
    }
    
    void updateMin() {
        min_val = 2147483647;
        struct StackNode *curr = head;
        while(curr) {
            if(curr->value < min_val) {
                min_val = curr->value;
                min = curr;
            }
            curr = curr->prev;
        }
    }
    
    int getMin() {
        return(min_val);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
 
int main(int argc, char **argv) {
    MinStack* obj = new MinStack();
    //printf("minStack(%d) %d\n", obj->top(), obj->getMin());
    for(int i = 5; i > 0; i--) {
        obj->push(i);
       // obj->traverse();
        printf("%d: min=%d\n", i, obj->getMin());
    }
    //printf("minStack(%d) %d\n", obj->top(), obj->getMin());
    for(int i = 0; i < 5; i++) {
        obj->pop();
        //break;
       // obj->traverse();
        printf("%d: min=%d\n", i, obj->getMin());
        //break;
    }
    return(0);
}    

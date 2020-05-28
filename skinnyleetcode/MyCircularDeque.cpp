/*
 *	https://leetcode.com/problems/design-circular-deque/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class MyCircularDeque {
public:
    std::vector<int> deque;
    int size;
    int count;
    int front;
    int rear;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
        count = 0;
        front = k-1;
        rear = 0;
        deque.resize(size);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        bool tf = false;
        if(not isFull()) {        
            deque[front]=value;
            front = (front-1+size)%size;
            count++;
            tf = true;
        }
        return tf;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        bool tf = false;
        if(not isFull()) {
            deque[rear]=value;
            rear=(rear+1)%size;
            count++;
            tf = true;
        }
        return tf;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        bool tf = false;
        if(not isEmpty()) {
            front=(front+1)%size;
            count--;
            tf = true;
        }
        return tf;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        bool tf = false;
        if(not isEmpty()) {  
            rear=(rear-1+size)%size;
            count--;
            tf = true;
        }
        return tf;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return not isEmpty() ? deque[(front+1)%size] : -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return not isEmpty() ? deque[(rear-1+size)%size] : -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
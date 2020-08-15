/*
 * https://leetcode.com/problems/min-stack/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class MinStack {
public:
    std::stack<int> stack;
    std::stack<std::pair<int,int>> mins;
    
    MinStack() {}
    
    void push(int x) {
        stack.push(x);
        if(mins.empty() or mins.top().first > x) { mins.push({x, 1}); }
        else if(x == mins.top().first) { mins.top().second++; }
    }
    void pop() {
        if(not stack.empty()) {
            if(stack.top() == mins.top().first) { mins.top().second--; }
            if(mins.top().second == 0) { mins.pop(); }
            stack.pop(); 
        }
    }
    int top() {
        return not stack.empty() ? stack.top() : -1;
    }
    int getMin() {
        return not mins.empty() ? mins.top().first : -1;
    }
};














class MinStack0 {
public:
    /** initialize your data structure here. */
    std::stack<int> data_stack;
    std::stack<int> min_stack;
    MinStack0() {}
    
    void push(int x) {
        data_stack.push(x);
        if(min_stack.empty() or min_stack.top() >= x) {min_stack.push(x);}
            
    }
    
    void pop() {
        if(not data_stack.empty()) { 
            if(data_stack.top() == min_stack.top()) min_stack.pop(); 
            data_stack.pop(); 
        }
        
    }
    
    int top() {
        return not data_stack.empty() ? data_stack.top() : 0;
    }
    
    int getMin() {
        return not min_stack.empty() ? min_stack.top() : 0;
    }
};


class MinStack2 {
public:
    /** initialize your data structure here. */
    std::stack<std::pair<int,int>> stack;
    MinStack2() {}
    
    void push(int x) {
        if(stack.empty()) stack.push({x, x});
        else { stack.push({x, min(stack.top().second, x)}); }
        
    }
    
    void pop() {
        if(not stack.empty()) { stack.pop(); }
        
    }
    
    int top() {
        return not stack.empty() ? stack.top().first : 0;
    }
    
    int getMin() {
        return not stack.empty() ? stack.top().second : 0;
    }
};


class MinStack1 {
public:
    /** initialize your data structure here. */
    std::stack<int> stack;
    std::map<int, int> map;
    MinStack1() {}
    
    void push(int x) {
        stack.push(x);
        map[x]++;
    }
    
    void pop() {
        if(not stack.empty()) {
            int x = stack.top(); 
            map[x]--; if(map[x]==0) map.erase(x);
            stack.pop();
        }
        
    }
    
    int top() {
        return not stack.empty() ? stack.top() : 0;
    }
    
    int getMin() {
        return not stack.empty() ? map.begin()->first : 0;
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
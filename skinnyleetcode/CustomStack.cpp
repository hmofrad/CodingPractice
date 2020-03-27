/*
 *  https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class CustomStack {
public:
    int size = 0;
    std::vector<int> stack;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < size)
            stack.push_back(x);
    }
    
    int pop() {
        int ret = -1;
        if(not stack.empty()) {
            ret = stack.back();
            stack.pop_back();
        }
        return(ret);
    }
    
    void increment(int k, int val) {
        int b = (k < stack.size()) ? k : stack.size();
        for(int i = 0; i < b; i++)
            stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
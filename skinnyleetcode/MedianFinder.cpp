/*
 * https://leetcode.com/problems/find-median-from-data-stream/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class MedianFinder {
public:
    /** initialize your data structure here. */
    std::priority_queue<int, std::vector<int>> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if(left.size() < right.size()) { left.push(right.top()); right.pop(); }
        
    }
    
    double findMedian() {
        //int size = left.size() + right.size();
        //return size ? size%2 ? left.top() : (double) (left.top() + right.top())/2 : 0;
        return left.size() > right.size() ? left.top() : (double) (left.top() + right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
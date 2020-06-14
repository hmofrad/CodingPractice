/*
 * https://leetcode.com/problems/my-calendar-ii/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class MyCalendarTwo {
public:
    
    std::vector<std::pair<int, int>> times;
    std::vector<std::pair<int, int>> overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for(std::pair<int, int>& overlap: overlaps) {
            if(end > overlap.first and start < overlap.second) return false;
        }
        for(std::pair<int, int>& time: times) {
            if(end > time.first and start < time.second) overlaps.push_back({max(start, time.first), min(end,time.second)});
        }
        
        times.push_back({start, end});
        return true;
        
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
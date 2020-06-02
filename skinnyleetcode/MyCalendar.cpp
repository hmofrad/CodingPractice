/*
 *  https://leetcode.com/problems/my-calendar-i/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class MyCalendar {
public:
    std::vector<std::pair<int,int>> times1; 
    std::set<std::pair<int,int>> times; 
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto lb = times.lower_bound({start, end});
        if(lb != times.end() and lb->first < end) return false;
        if(lb != times.begin() and start < (--lb)->second) return false;
        times.insert({start, end});
        return true;
    }
    
    bool book1(int start, int end) {
        for(std::pair<int, int>& time: times1) {
            if(time.first < end and start < time.second) return false;
        }
        times1.push_back({start, end});
        return true;
    }
};

   

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
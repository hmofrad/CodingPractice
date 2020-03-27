/*
 *  https://leetcode.com/problems/number-of-recent-calls/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class RecentCounter {
public:
    std::deque<int> times;
    int min;
    int max;
    RecentCounter() {
        min = 0;
        max = 0;
    }
    
    int ping(int t) {
        times.push_back(t);
        while(times.front() < t- 3000) {
            times.pop_front();
        }
        return(times.size());
        /*
        int l = (t - 3000 > 0) ? t - 3000 : 0;
        int r = t;
        times.push_back(t);
        int n = 0;
        for(auto tt: times) {
            if(tt >= l and tt <=r) n++;
        }
        return(n);
        */
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
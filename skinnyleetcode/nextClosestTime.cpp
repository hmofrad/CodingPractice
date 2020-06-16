/*
 * https://leetcode.com/problems/next-closest-time/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    char find_next(std::set<int>& set, int digit, int limit) {
        if(digit < limit) {
            auto it = set.find(digit);
            if(next(it)==set.end()) { return *set.begin()+'0'; }
            if(next(it) != set.end() and *next(it) <= limit) { return *next(it)+'0'; }   
        }
        return *set.begin()+'0'; 
    }
    
    
    string nextClosestTime(string time) {
        std::vector<int> digits = {time[0]-'0', time[1]-'0', time[3]-'0', time[4]-'0'};
        std::set<int> set(digits.begin(), digits.end());
        
        std::string time_next(time);
        time_next[4]=find_next(set, time[4]-'0',10);
        if(time_next[4]>time[4]) { return time_next; }
        
        time_next[3]=find_next(set, time[3]-'0',5);
        if(time_next[3]>time[3]) { return time_next; }
        
        time_next[1]=find_next(set, time[1]-'0', time[0]=='2' ? 3 : 10);
        if(time_next[1]>time[1]) { return time_next; }
        
        time_next[0]=find_next(set, time[0]-'0',2);
        if(time_next[0]<time[0]) { return time_next; }
        
        return time_next;
    }
};















class Solution1 {
public:
    bool is_valid_hour(int hour) {
        return hour>=0 and hour<=23;
    }
    
    bool is_valid_minute(int minute) {
        return minute>=0 and minute<=59;
    }
    
    int diff(int h1, int m1, int h2, int m2) {
        if(h1>h2) return diff(h2, m2, h1, m1);
        
        int d = 0;
        if(h1==h2) { d = 24-abs(m1-m2); }
        else { d = h2-h1-m1+m2; }
        return d;        
    }
    
    int max_diff;
    std::string next_time;
    int backtrack(std::vector<int>& digits, int index, int hour0, int minute0, int hour1, int minute1) {
        if((hour1 != 0 and minute1 != 0) and (not is_valid_hour(hour1) or not is_valid_minute(minute1))) return INT_MAX;
        if(index == digits.size()) { 
            printf("%d %d\n", hour1, minute1);
            int d = diff(hour0, minute0, hour1, minute1); 
            if(d<max_diff) { 
                max_diff=d; 
                next_time = to_string(hour1) + ":" + to_string(minute1);
            } 
        }
        
        for(int i = 0; i < digits.size(); i++) {
            if(hour1==0) hour1=10*digits[i];
            else hour1+=digits[i];
            if(minute1==0) minute1=10*digits[i];
            else minute1+=digits[i];
            backtrack(digits, index+1, hour0, minute0, hour1, minute1);
            if(hour1>9)hour1-=10*digits[i];
            else hour1-=digits[i];
            if(minute1>9) minute1-=10*digits[i];
            else minute1-=digits[i];
        }
        
        return max_diff;
    }
    
    string nextClosestTime(string time) {
        std::unordered_set<int> set;
        set.insert(time[0]-'0');
        set.insert(time[1]-'0');
        set.insert(time[3]-'0');
        set.insert(time[4]-'0');
        std::vector<int> digits;
        for(auto s: set) digits.push_back(s);

        int hour0 = (time[0]-'0')*10 + (time[1]-'0');
        int minute0 = (time[3]-'0')*10 + (time[4]-'0');
        max_diff = INT_MAX;
        next_time = time;
        backtrack(digits, 0, hour0, minute0, 0, 0);
        
        return next_time;
    }
};
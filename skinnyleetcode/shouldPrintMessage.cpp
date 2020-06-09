/*
 * https://leetcode.com/problems/logger-rate-limiter/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Logger {
public:
    std::deque<std::pair<std::string, int>> queue;
    std::unordered_set<std::string> set;
    Logger() {}
    bool shouldPrintMessage(int timestamp, string message) {
        while(not queue.empty() and timestamp - queue.front().second>=10) {
            set.erase(queue.front().first);
            queue.pop_front(); 
            
        }
        
        if(set.count(message)) return false; 
        queue.push_back({message, timestamp});
        set.insert(message);

        return true;
    }
};



class Logger2 {
public:
    std::unordered_map<std::string, int> times;
    Logger2() {}
    bool shouldPrintMessage(int timestamp, string message) {
        bool print = false;
        if(times.count(message)==0) {print = true; times[message]=timestamp;}
        else{
            int& timestamp0 = times[message];
            if(timestamp-timestamp0>=10) {
                timestamp0=timestamp;
                print = true;
            }
        }
        return print;
    }
};

























class Logger1 {
public:
    /** Initialize your data structure here. */
    std::unordered_map<std::string, int> my_map;
    std::deque<std::pair<int, std::string>> queue;
    int size = 10;
    int head = 0;
    int tail = 0;
    int count = 0;
    Logger1() {
        //queue.resize(size);
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage1(int timestamp, string message) {
      //  printf("T=%d M=%s %d\n", timestamp, message.c_str(), queue.size());
        bool print = true;
        
        while(true) {
            if(timestamp >= 10 and queue.front().first + 10 <= timestamp and not queue.empty()) {
                queue.pop_front();
            }
            else {
                break;
            }
        }
        
        for(auto node: queue) {
            if(node.second == message) {
                print = false;
                break;
            }
        }
        
        if(print) queue.push_back({timestamp, message});
        return(print);
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(my_map.find(message) == my_map.end()) {
            my_map[message] = timestamp;
            return(true);
        }
        
        //bool print = true;
        int old_timestamp = my_map[message];
        if(timestamp - old_timestamp >= 10) {
            my_map[message] = timestamp;
            return(true);
        }

        return(false);
    }
    
    
    
    
    
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
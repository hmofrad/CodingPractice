/*
 *	https://leetcode.com/problems/time-based-key-value-store/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class TimeMap {
public:
    /** Initialize your data structure here. */
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> db;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back(std::make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        std::string value;
        if(db.count(key)) {
            std::vector<std::pair<std::string, int>>& vec = db[key];
            int size = vec.size();
            for(int i = size-1; i >= 0; i--) {
                std::pair<std::string, int>& p = vec[i];
                std::string& value0 = p.first;
                int timestamp0 = p.second;
                if(timestamp0<=timestamp) {value = value0; break;}
            }
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
/*
 *	https://leetcode.com/problems/map-sum-pairs/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class MapSum {
public:
    /** Initialize your data structure here. */
    std::unordered_map<std::string, int> db;
    std::unordered_map<std::string, std::vector<std::string>> prefixes;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(db.count(key) == 0) {
            for(int i = 1; i <= key.size(); i++) {
                std::string k = key.substr(0, i);
                prefixes[k].push_back(key);
            }
        }
        db[key]=val;
    }
    
    int sum(string prefix) {
        int s = 0;
        for(auto k: prefixes[prefix]) {
            s+=db[k];
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
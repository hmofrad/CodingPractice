/*
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class RandomizedCollection {
public:
    std::unordered_map<int, std::vector<int>> map;
    std::vector<std::pair<int, int>> vec;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        map[val].push_back(vec.size());
        vec.push_back({val, map[val].size()-1});
        return map[val].size()==1;
    }
    

    bool remove(int val) {
        if(map.count(val)) {
            std::pair<int, int> last = vec.back();
            int v = last.first;
            int i = last.second;
            int index = map[val].back();
            map[v][i] = index;
            vec[index] = last;
            map[val].pop_back();
            if(map[val].empty()) { map.erase(val); }
            vec.pop_back();
            return true;
        }
        
        return false;
    }
    
    
    int getRandom() {
        return vec[rand()%vec.size()].first;
    }
};


class RandomizedCollection0 {
public:
    std::unordered_map<int, std::vector<int>> map;
    std::vector<int> vec;
    /** Initialize your data structure here. */
    RandomizedCollection0() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        map[val].push_back(vec.size());
        vec.push_back(val);
        return map[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(map.empty() or map.count(val)==0) { return false; }
        
        int index = map[val].back();
        map[val].pop_back();
        if(map[val].empty()) { map.erase(val); }
        
        if(index == vec.size()-1) { vec.pop_back(); return true; }
        
        int val0 = vec.back();
        map[val0].back() = index;
        vec[index] = val0;
        vec.pop_back();
        return true;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
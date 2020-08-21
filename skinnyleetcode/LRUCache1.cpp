/*
 * https://leetcode.com/problems/lru-cache/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class LRUCache {
public:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    std::list<std::pair<int, int>> list;
    int size = 0;
    LRUCache(int capacity) {
        cache.reserve(capacity);
        size = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            std::list<std::pair<int, int>>::iterator& it = cache[key];
            int value = cache[key]->second;
            list.splice(list.begin(), list, it);
            return value; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            std::list<std::pair<int, int>>::iterator& it = cache[key];
            it->second = value;
            list.splice(list.begin(), list, it);
            return;
        }
        
        if(cache.size() == size) {
            int victim = list.back().first;
            list.pop_back();
            cache.erase(victim);
        }
        
        list.push_front({key, value});
        cache[key] = list.begin();
    }
};



class LRUCache22 {
public:
    int capacity;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    std::list<std::pair<int, int>> list; 
    
    LRUCache22(int capacity_) {
        capacity = capacity_;
        cache.reserve(capacity);
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        list.splice(list.begin(), list, it->second);
        return it->second->second;    
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()) {
            list.splice(list.begin(), list, it->second);
            it->second->second = value;
            return;
        }
        
        if(cache.size() == capacity) {
            int victim = list.back().first;
            list.pop_back();
            cache.erase(victim);
        }
        list.emplace_front(key, value);
        cache[key]=list.begin();
        
    }
};

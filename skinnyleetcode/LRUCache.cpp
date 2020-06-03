/*
 *  https://leetcode.com/problems/lru-cache/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class LRUCache {
public:
    int capacity;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    std::list<std::pair<int, int>> list; 
    
    LRUCache(int capacity_) {
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


class LRUCache0 {
public:
    
    
    std::vector<int> queue;
    //std::vector<int> aging;
    std::unordered_map<int, int> cache;
    std::unordered_map<int, int> cahce2index;
    int size = 0;
    int count = 0;
    int index = 0;
    //struct compare { bool operator()(std::pair<int,int> a, std::pair<int,int> b) { return a.second < b.second; } };
    //std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, compare> queue;
    
    LRUCache0(int capacity) {
        size = capacity;
        count = 0;
        cache.reserve(size);
        queue.resize(size);
    }
    
    int get(int key) {
        int ret = -1;
        if(cache.count(key)) ret = cache[key];
        //if(ret!=-1) {
          //  queue[]
        //}
        return ret;
    }
    
    void put(int key, int value) {
        
        if(count == size) {
            int victim = queue[index];
            index = (index+1)%size;
            cache.erase(victim);
            cache[key]=value;
        }
        else {
            cache[key]=value;
            queue[count]=key;
            count++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
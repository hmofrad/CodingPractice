/*
 *  https://leetcode.com/problems/design-hashmap/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class MyHashMap {
public:
    const int n_buckets = 2069;
    std::vector<std::vector<std::pair<int,int>>> map;
    
    MyHashMap() {
        map.resize(n_buckets);
    }
    
    
    void put(int key, int value) {
        int k = key%n_buckets;
        if(map[k].empty()) map[k].push_back({key, value});
        else {
            std::vector<std::pair<int,int>>& bucket = map[k];
            int size = bucket.size();
            for(int i = 0; i < size; i++) {
                if(bucket[i].first == key) {
                    bucket[i].second = value;
                    return;
                }
            }
            bucket.push_back({key, value});
        }
    }
    
    int get(int key) {
        int k = key%n_buckets;
        if(map[k].empty()) return -1;
        else {
            std::vector<std::pair<int,int>>& bucket = map[k];
            int size = bucket.size();
            for(int i = 0; i < size; i++) {
                if(bucket[i].first == key) {
                    return bucket[i].second;
                }
            }
        }
        return -1;
    }
    

    void remove(int key) {
        int k = key%n_buckets;
        if(map[k].empty()) return;
        else {
            int index = -1;
            std::vector<std::pair<int,int>>& bucket = map[k];
            int size = bucket.size();
            for(int i = 0; i < size; i++) {
                if(bucket[i].first == key) {
                    index = i;
                    break;
                }
            }
            if(index != -1) bucket.erase(bucket.begin()+index);
        }
    }
};



class MyHashMap1 {
public:
    /** Initialize your data structure here. */
    const int LEN = 1000001;
    std::vector<bool> bmap;
    std::vector<int> vmap;
    MyHashMap1() {
        bmap.resize(LEN);
        vmap.resize(LEN);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if(not bmap[key]) bmap[key] = true;
        vmap[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int v = -1;
        if(bmap[key]) v = vmap[key];
        return v;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(bmap[key]) {
            bmap[key] = false;
            vmap[key] = 0;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
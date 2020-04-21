/*
 *  https://leetcode.com/problems/design-hashset/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class MyHashSet {
public:
    /** Initialize your data structure here. */
    const int nbuckets = 2069;
    std::vector<std::vector<int>> buckets;
    MyHashSet() {
        buckets.resize(nbuckets);
    }
    
    void add(int key) {
        int k = key%nbuckets;
        std::vector<int>& bucket = buckets[k];
        if(bucket.empty() or (std::find(bucket.begin(), bucket.end(), key) == bucket.end())) bucket.push_back(key);
    }
    
    void remove(int key) {
        int k = key%nbuckets;
        std::vector<int>& bucket = buckets[k];
        if(not bucket.empty()) {
            int size = bucket.size();
            int index = -1;
            for(int i = 0; i < size; i++) {
                if(bucket[i] == key) {index=i; break;}
            }
            if(index != -1) bucket.erase(bucket.begin()+index);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = key%nbuckets;
        std::vector<int> bucket = buckets[k];
        
        return ((not bucket.empty()) and (std::find(bucket.begin(), bucket.end(), key) != bucket.end()));
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
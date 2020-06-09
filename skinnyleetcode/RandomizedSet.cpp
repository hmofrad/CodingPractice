/*
 * https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class RandomizedSet {
public:
    std::vector<int> arr;
    std::unordered_map<int, int> map;
    RandomizedSet() {
        srand(time(NULL));
    }
    

    bool insert(int val) {
        if(map.count(val)) return false;
        map[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(map.count(val)==0) return false;
        int index = map[val];
        map.erase(val);
        if(index==arr.size()-1) {
            arr.pop_back();
            return true;
        }
        
        arr[index]=arr[arr.size()-1];
        arr.pop_back();
        map[arr[index]]=index;
        return true;
    }
    

    int getRandom() {
        return arr[rand()%arr.size()];
    }
};


class RandomizedSet1 {
public:
    
    std::unordered_set<int> set;
    RandomizedSet1() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        return set.insert(val).second;
    }
    
    bool remove(int val) {
        return set.erase(val);
    }
    
    
    int getRandom() {
        
        return *std::next(set.begin(),rand()%set.size());
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
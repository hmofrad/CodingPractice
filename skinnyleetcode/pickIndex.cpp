/*
 * https://leetcode.com/problems/random-pick-with-weight/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> p;
    Solution(vector<int>& w) {
        p.resize(w.size());
        p.front()=w.front();
        for(int i = 1; i < w.size(); i++) {
            p[i]=w[i]+p[i-1];
        }
    }
    int pickIndex() {
        int r = rand() % p.back();
        return upper_bound(p.begin(), p.end(), r)-p.begin();
    }
    int pickIndex0() {
        float r = (float) rand()/RAND_MAX;
        float t = r * p.back();
        /*
        for(int i = 0; i < p.size(); i++) {
            if(t<p[i]) { return i; }
        }
        return p.size()-1;
        */
        return upper_bound(p.begin(), p.end(), t)-p.begin();
    }
};

class Solution0 {
public:
    vector<int> nums;
    std::vector<int> vec;
    Solution0(vector<int>& w) {
        nums = w;
        for(int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            for(int j = 0; j < v; j++) {
                vec.push_back(i);
                bool shuffle = rand()%2;
                if(shuffle) {
                    int index = rand()%vec.size();
                    std::swap(vec[index], vec.back());
                }
            }
        }
    }
    
    int pickIndex() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
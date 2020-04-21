/*
 *  https://leetcode.com/problems/top-k-frequent-elements/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> value2freq;
        for(int num: nums) value2freq[num]++;
        std::map<int, std::vector<int>> freq2value;
        for(auto v: value2freq) {
            freq2value[v.second].push_back(v.first);
        }
        
        std::vector<int> ans;
        for(auto it = freq2value.rbegin(); it != freq2value.rend(); it++) {
            int freq = it->first;
            std::vector<int> values = it->second;
            for(int v: values) {ans.push_back(v); k--; if(not k) break;}
            if(not k) break;
        }
        return ans;
        /*
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int maxIndex = 0;
        int maxCount = 1;
        int currentIndex = 0;
        int currentCount = 0;
        for(int i = 1; i < size; i++) {
            if(s[currentIndex] == s[i]) currentCount++;
            else {
                if(currentCount > )
            }
        }
        */
    }
    vector<int> topKFrequent1(vector<int>& nums, int k) {
std::vector<int> topk(k);
    
    std::sort(nums.begin(), nums.end());
    
    std::vector<int> keys;
    std::vector<int> vals;
    
    keys.push_back(nums[0]);
    vals.push_back(1);
    
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            vals.back()++;
        }
        else {
            keys.push_back(nums[i]);
            vals.push_back(1);
        }
    }
    
    //for(int i = 0; i < keys.size(); i++) {
    //    printf("%d %d %d\n", i, keys[i], vals[i]);
        
    //}
    
    for(auto &k: topk) {
        int idx = 0;
        int val = 0;
        for(int i = 0; i < vals.size(); i++) {
            if(vals[i] > val) {
                val = vals[i];
                idx = i;
            }
        }
        k = keys[idx];
        vals[idx] = 0;
    }

    return(topk);
    }
};
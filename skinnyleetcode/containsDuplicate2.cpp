/*
 *	https://leetcode.com/problems/contains-duplicate/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        bool dup = false;
        for(int i = 0; i < size-1; i++) {
            if(nums[i]==nums[i+1]) {dup = true; break;}
        }
        return dup;
    }
    bool containsDuplicate1(vector<int>& nums) {
    bool ret = false;
    int n = nums.size();
    if(n > 1) {
        std::unordered_set<int> hash;
        for(auto v: nums) {
            if (hash.find(v) == hash.end()) {
                hash.insert(v);
            }
            else {
                ret = true;
                break;                
            }
        }
    }
    return(ret);
    }
};
/*
 * https://leetcode.com/problems/jump-game/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int pos = nums.size()-1;
        for(int i = size-1; i>= 0; i--) {
            pos = (i+nums[i]>=pos) ? i : pos;
        }
        return pos == 0;
    }
    bool canJump2(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        for(int reach = 0; i<=min(size-1, reach); i++) reach = max(i+nums[i], reach);
        return i==size;
    }
    
    
    bool dfs1(std::vector<int>& nums, int index) {
        if(index==nums.size()-1) return true;
        if(index>=nums.size()) return false;
        bool ret = false;
        int jump = nums[index];
        for(int i = 1; i <= jump; i++) {    
            ret |= dfs1(nums,index+i);
            if(ret) break;
        }
        
        return ret;
    }
    
    bool dfs(std::vector<int>& nums, int index, std::vector<int>& cache) {
        if(cache[index]) { return cache[index] == 1 ? true : false; } 
        
        int jump = nums[index];
        for(int i = index+1; i <= min((int)nums.size()-1, index+jump); i++) {
            if(dfs(nums, i, cache)) {
                cache[index]=1;
                return true;
            }
        }
        cache[index]=2;
        return false;
    }
    
    bool canJump1(vector<int>& nums) {
        std::vector<int> cache(nums.size());
        cache[nums.size()-1]=1;
        return dfs(nums, 0, cache);
    }
};
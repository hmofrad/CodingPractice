/*
 * https://leetcode.com/problems/jump-game-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int njumps = 0, curr_end = 0, curr_farthest = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            curr_farthest = max(curr_farthest, i+nums[i]);
            if(i==curr_end) {
                njumps++;
                curr_end=curr_farthest;
            }
        }
        return njumps;
    }
    int jump2(vector<int>& nums) {
        int size = nums.size();
        if(size<2) return 0;
        
        int max_position = nums[0];
        int max_steps = nums[0];
        int njumps=1;
        for(int i = 1; i < size; i++) {
            if(max_steps<i) {
                njumps++;
                max_steps=max_position;
            }
            max_position = max(max_position, i+nums[i]);
        }
        return njumps;
    }
    
    int dfs(std::vector<int>& nums, int index, int njumps) {
        if(nums.size()-1==index) return njumps;
        int n = INT_MAX;
        int end = min((int)nums.size()-1, index+nums[index]);
        for(int i = index+1; i<=end; i++) {
            n = min(n, dfs(nums,i,njumps+1));
        }
        return n;
    }
    int jump1(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};
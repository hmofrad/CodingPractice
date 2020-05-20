/*
 *	https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int left = 0; 
        int right = size-1;
        int nmoves = 0;
        while(left < right) {
            nmoves+=nums[right]-nums[left];
            left++;
            right--;
        }
        return nmoves; 
    }
    
    int minMoves20(vector<int>& nums) {
        int size = nums.size();
        int median = get_median(nums);
        //printf("%d\n", median);
        int nmoves = 0;
        for(int i = 0; i < size; i++) {
            nmoves += abs(median - nums[i]);
        }
        
        return nmoves;
    }
    int get_median(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        return (size%2) ? nums[size/2] : (nums[(size/2)-1]+nums[size/2])/2;
    }
};
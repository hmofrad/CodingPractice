/*
 * https://leetcode.com/problems/trapping-rain-water/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size-1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while(left<right) {
            if(height[left]<=height[right]) {
                left_max = max(left_max, height[left]);
                ans += left_max-height[left];
                left++;
            }
            else {
                right_max = max(right_max, height[right]);
                ans += right_max-height[right];
                right--;
            }
        }
        
        return ans;
    }
    int trap2(vector<int>& height) {
        int size = height.size();
        int left = 0; int right = size-1;
        int ans = 0;
        int left_max = 0; int right_max = 0;
        
        while(left<=right) {
            if(height[left]<=height[right]) {
                if(height[left]>=left_max) left_max=height[left];
                else ans+=left_max-height[left];
                left++;
            }
            else {
                if(height[right]>=right_max) right_max=height[right];
                else ans+=right_max-height[right];
                right--;
            }
            
        }
        
        return ans;
    }
    int trap1(vector<int>& height) {
        int size = height.size();
        int ans = 0;
        for(int i = 0; i < size; i++) {
            int left_max = 0;
            int right_max = 0;
            for(int j = i; j >= 0 ; j--) left_max = max(left_max, height[j]);
            for(int j = i; j < size ; j++) right_max = max(right_max, height[j]);
            
            ans += min(left_max, right_max)-height[i];
        }
        return ans;
    }
};
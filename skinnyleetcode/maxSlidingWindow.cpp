/*
 * https://leetcode.com/problems/sliding-window-maximum/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() or k <= 0 or k>nums.size()) { return std::vector<int>(); }
        int size = nums.size();
        std::vector<int> ans;
        std::deque<int> queue;
        for(int i = 0; i < size; i++) {
            while(not queue.empty() and queue.front() == i-k) { queue.pop_front(); }
            while(not queue.empty() and nums[queue.back()] < nums[i]) { queue.pop_back(); }
            queue.push_back(i);
            if(i>=k-1) ans.push_back(nums[queue.front()]);
        }
        return ans;
    }
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        if(nums.empty() or k == 0 or k>nums.size()) { return std::vector<int>(); }
        if(k==1) { return nums; }
        std::vector<int> ans;
        int size = nums.size();
        
        int mx = INT_MIN;
        std::stack<int> stack;
        for(int i = 0; i < k; i++) {
            mx=max(mx, nums[i]);
        }
        ans.push_back(mx);
        int j = 0;
        for(int i = k; i < size; i++) {
            if(nums[i]>=ans.back()) { ans.push_back(nums[i]); }
            else if(nums[j] < ans.back()) { ans.push_back(ans.back()); }
            else {
                int l = j+1;
                int t = nums[j+1];
                while(l<=i) {t = max(t, nums[l++]);}
                ans.push_back(t);
            }
            j++;
        }
        return ans;
    }
    vector<int> maxSlidingWindow0(vector<int>& nums, int k) {
        if(nums.empty() or k == 0) { return std::vector<int>(); }
        
        std::vector<int> ans;
        int size = nums.size();
        for(int i = 0; i <= size-k; i++) {
            int mx = INT_MIN;
            for(int j = i; j<i+k; j++) {
                mx = max(mx, nums[j]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
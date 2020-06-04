/*
 *  https://leetcode.com/problems/maximum-average-subarray-i/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    double findMaxAverage1(vector<int>& nums, int k) {
        int size = nums.size();
        std::vector<int> prefix_sum(size);
        prefix_sum[0] = nums[0];
        for(int i = 1; i < size; i++) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }
        
        double avg = (double) prefix_sum[k-1] / k;
        
        for(int i = k; i < size; k++) {
            avg = max(avg, (double) prefix_sum[i]-prefix_sum[i-k]/k);
        }
        
        return avg;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        if(size<k) return 0;
        
        double sum = std::accumulate(nums.begin(), nums.begin()+k,0.0);
        double max_avg = (double) sum/k;
        for(int i = k, j=0; i < size; i++, j++) {
            sum+=-nums[j]+nums[i];
            double new_avg = (double) sum/k;
            max_avg = max(max_avg, new_avg);
        }
        return max_avg;
    }
};
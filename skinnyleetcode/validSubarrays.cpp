/*
 *  https://leetcode.com/problems/number-of-valid-subarrays/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int validSubarrays1(vector<int>& nums) {
        int m = nums.size();
        int n = 0;
        for(int i = 0; i < m; i++) {
            //printf("1.A[%d]=%d n=%d\n", i, nums[i], n);
            std::vector<int> v;
            v.push_back(nums[i]);
            n++;

            for(int j = i+1; j < m; j++) {
                if(v.front() <= nums[j]) {
                    v.push_back(nums[j]);
                    n++;
                }
                else {
                    break;
                }
            }
            //printf("2.A[%d]=%d n=%d\n", i, nums[i], n);
            //n += (v.size() > 1) ? v.size() : 0;
        }
        return(n);
    }
    
    int validSubarrays(vector<int>& nums) {
        std::vector<int> stack;
        int n = 0;
        for(auto num: nums) {
            printf("0.%d %d: ", num, n);
            for(auto s: stack) {printf("%d ", s);} printf("\n");
            while(not stack.empty() and stack.back() > num) {
                stack.pop_back();
            }
            stack.push_back(num);
            n += stack.size();
            printf("1.%d %d: ", num, n);
            for(auto s: stack) {printf("%d ", s);} printf("\n");
        }
        return(n);
    }
    
};
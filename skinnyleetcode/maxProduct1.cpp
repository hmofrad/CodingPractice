/*
 * https://leetcode.com/problems/maximum-product-subarray/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int l = 0;
        int r = 0;
        int a = INT_MIN;
        for(int i = 0; i < size; i++) {
            l = l ? l*nums[i] : nums[i];
            r = r ? r*nums[size-i-1] : nums[size-i-1];
            a = max({a,l,r});
        }
        return a;
    }
    int maxProduct3(vector<int>& nums) {
        int size = nums.size();
        int r = nums[0];
        for(int i = 1, imax = r, imin = r; i < size; i++) {
            //if(nums[i]<0) std::swap(imin, imax);
            //imax = max(nums[i], imax*nums[i]);
            //imin = min(nums[i], imin*nums[i]);
            std::vector<int> temp = {nums[i], imax*nums[i], imin*nums[i]};
            imax = *std::max_element(temp.begin(), temp.end());
            imin = *std::min_element(temp.begin(),temp.end());
            r = max(r, imax);
        }
        return r;
    }
    int maxProduct2(vector<int>& nums) {
        int size = nums.size();
        std::vector<std::vector<int>> dp(size+1, std::vector<int>(size+1,0));
        for(int j = 1; j <= size; j++) dp[0][j]=nums[j-1];
        for(int i = 1; i <= size; i++) dp[i][0]=nums[i-1];
        
        for(int i = 1; i <= size; i++) {
            for(int j = 1; j <= size; j++) {
                dp[i][j]=min(dp[i-1][j], dp[i-1][j-1]*nums[j-1]);
            }
        }
        
        for(int i = 0; i <= size; i++) {
            for(int j = 0; j <= size; j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        
        return dp[size][size];
    }
    int maxProduct1(vector<int>& nums) {
        //nums={0,2};
        if(nums.empty()) return 0;
        int max_prod = nums[0];
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            int prod=nums[i];
            max_prod = max(max_prod, prod);
            for(int j = i+1; j < size; j++) {
                prod*=nums[j];
                max_prod = max(max_prod, prod);
            }
        }
        return max_prod;
    }
};
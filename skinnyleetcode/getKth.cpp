/*
 *  https://leetcode.com/problems/sort-integers-by-the-power-value/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> dp;
    int power(int num) {
        if(num == 1) return 0;
        
        if(num%2) {
            return(1+power((3*num)+1));
        }
        else {
            return(1+power(num/2));
        }
    }
    
    int getKth(int lo, int hi, int k) {
        dp.resize(hi+1);
        //dp[0] = 0;
        //dp[1] = 0;
        for(int i = 2; i <= hi; i++) {
            dp[i] = power(i);
            //printf("%d %d\n", i, dp[i]);
        }
        //for(int i = 0; i < dp.size(); i++) {
          //  printf();
        //}
        
        //for(auto n: dp){printf("[%d %d] ", n, power(n));} printf("\n");
        
        
        
        //printf("%d %d \n", lo, power(lo));
        //printf("%d %d\n", hi, power(hi));
        
        std::vector<int> nums(hi-lo+1);
        std::iota(nums.begin(), nums.end(), lo);
        //for(auto n: nums){printf("[%d %d] ", n, power(n));} printf("\n");
        std::sort(nums.begin(), nums.end(), [this](const int a, const int b) {
            if(dp[a] < dp[b]) {
                return true;
            }
           else if(dp[a] == dp[b]) {
               return a<b;
           }
           else {
                   return false;
           }});
        
            //for(auto n: nums){printf("[%d %d] ", n, power(n));} printf("\n");
        return(nums[k-1]);
    }
    
    int getKth1(int lo, int hi, int k) {
        std::vector<int> nums(hi-lo+1);
        std::iota(nums.begin(), nums.end(), lo);
        //for(auto n: nums){printf("[%d %d] ", n, power(n));} printf("\n");
        std::sort(nums.begin(), nums.end(), [this](const int a, const int b) {
            if(power(a) < power(b)) {
                return true;
            }
           else if(power(a) == power(b)) {
               return a<b;
           }
           else {
                   return false;
           }});
           // for(auto n: nums){printf("[%d %d] ", n, power(n));} printf("\n");
        return(nums[k-1]);
    }
};
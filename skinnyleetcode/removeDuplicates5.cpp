/*
 * https://leetcode.com/problems/single-number-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        for(int n: nums) {
            one = ~two & (one^n);
            two = ~one & (two^n);
        }
        return one;
    }
    int singleNumber2(vector<int>& nums) {
        
        std::unordered_set<int> set(nums.begin(), nums.end());
        long long sum_arr = 0;
        for(int n: nums) sum_arr += (long) n;
        long long sum_set = 0;
        for(int s: set) sum_set += (long) s;
        printf("%lld %lld\n", sum_arr, sum_set);
        return (int) ((long long) (3*sum_set) - sum_arr)/2;
    }
    int singleNumber1(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for(int n: nums) { map[n]++; }
        int unique = -1;
        for(auto m: map) {
            if(m.second==1) {unique=m.first; break;}
        }
        return unique;
    }
};
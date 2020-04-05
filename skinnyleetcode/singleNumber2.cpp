/*
 *  https://leetcode.com/problems/single-number/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int n: nums) {
            a ^=n;
        }
        return a;
    }
    
    int singleNumber1(vector<int>& nums) {
        std::unordered_map<int, int> my_map;
        for(int n: nums) {my_map[n]++;}
        for(auto k: my_map) {
            if(k.second==1) return k.first;
        }
        return -1;
    }
};
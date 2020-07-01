/*
 * https://leetcode.com/problems/majority-element-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) return std::vector<int>();
        int size = nums.size();
        std::unordered_set<int> set;
        int value1 = 0; int count1 = 0;
        int value2 = 1; int count2 = 0;
        for(int num: nums) {
            if(value1==num) {count1++;}
            else if(value2==num) {count2++;}
            else if(count1==0) {value1=num; count1=1;}
            else if(count2==0) {value2=num; count2=1;}
            else {count1--; count2--;}
        }
        std::vector<int> ans;
        int c1 = 0, c2 = 0;
        for(int num: nums) {
            if(num == value1) c1++;
            else if(num == value2) c2++;
        }
        if(c1>size/3) ans.push_back(value1);
        if(c2>size/3) ans.push_back(value2);
        return ans;
    }
};
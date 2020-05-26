/*
 *	https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        std::unordered_map<int, int> map;
        for(int i = 0; i < size; i++) {
            map[target-numbers[i]]=i+1;
        }
        std::vector<int> ans;
        for(int i = 0; i < size; i++) {
            if(map.count(numbers[i])) {
                if(map[numbers[i]] > i+1)  ans = {i+1, map[numbers[i]]};
                else ans = {map[numbers[i]], i+1}; 
                break;
            }
        }
        return ans;
    }
    vector<int> twoSum1(vector<int>& numbers, int target) {
        int size = numbers.size();
        int left = 0;
        int right = size-1;
        while(left<right) {
            int sum = numbers[left]+numbers[right];
            if(sum==target) break;
            else if(sum<target) left++;
            else right--;
        }
        return std::vector<int>({left+1, right+1});
    }
};
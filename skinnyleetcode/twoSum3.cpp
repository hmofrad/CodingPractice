/*
 * https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/508/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ans;
        std::unordered_map<int, int> map;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            int c = target-nums[i];
            if(map.count(c)) { return {map[c], i}; }
            else { map[nums[i]] = i; }
        }
        return {-1,1};
    }
    
    vector<int> twoSum2(vector<int>& nums, int target) {
        //nums={3,3}; target = 6;
        //nums={3,2,4}; target=6;
        std::unordered_map<int, int> map;
        int size = nums.size();
        for(int i = 0; i < size; i++) map[target-nums[i]]=i;
        
        for(int i = 0; i < size; i++) {
            if(map.count(nums[i]) and map[nums[i]] != i) {//} and map[nums[i]].second != nums[i]) {
                int j = map[nums[i]];
                return i<j ? std::vector<int>({i,j}) : std::vector<int>({j,i});
            }
        }
        return {-1, -1};
    }
    vector<int> twoSum1(vector<int>& nums, int target) {
        int size = nums.size();
        std::vector<std::pair<int, int>> nums1(size);
        for(int i = 0; i < size; i++) nums1[i]={i,nums[i]};
        std::sort(nums1.begin(), nums1.end(), [](std::pair<int, int>a, std::pair<int, int>b) { return a.second<b.second; });
        int left = 0;
        int right = size-1;
        while(left<right) {
            int s = nums1[left].second+nums1[right].second;
            if(s!=target) {
                if(s<target) left++;
                else right--;
            }
            else {return {nums1[left].first, nums1[right].first};}
        }
        return {-1, -1};
    }
};
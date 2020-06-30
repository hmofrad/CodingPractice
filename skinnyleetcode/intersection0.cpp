/*
 * https://leetcode.com/problems/intersection-of-two-arrays/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());
        std::vector<int> ans;
        for(int num: set1) {
            if(set2.count(num)) { ans.push_back(num); }
        }
        return ans;
    }
    vector<int> intersection0(vector<int>& nums1, vector<int>& nums2) {
            std::vector<int> nums;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    int i1 = 0;
    int i2 = 0;
    while(i1 < nums1.size() and i2 < nums2.size()) {
       // printf("%d %d %d \n", i1, i2, nums.empty());
        if(nums1[i1] == nums2[i2]) {
            if(nums.empty()) {
                nums.push_back(nums1[i1]);
            }
            else if(nums.back() != nums1[i1]) {
                nums.push_back(nums1[i1]);
            }
            i1++;
            i2++;
        }
        else if(nums1[i1] < nums2[i2]) {
            i1++;
        }
        else {
            i2++;
        }
    }
    
    return(nums);
    }
};
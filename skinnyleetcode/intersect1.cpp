/*
 *  https://leetcode.com/problems/intersection-of-two-arrays-ii/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()> nums2.size()) return intersect(nums2, nums1);
        std::vector<int> nums;
        std::unordered_map<int, int> map;
        for(int& num: nums1) map[num]++;
        int k = 0;
        for(int num: nums2) {
            auto it = map.find(num);
            if(it != map.end() and --it->second>=0) nums.push_back(it->first);
        }
        return nums;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> nums;
        int m1 = nums1.size();
        int m2 = nums2.size();   

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int i1 = 0;
        int i2 = 0;
        while(i1 < m1 and i2 < m2) {
            if(nums1[i1] == nums2[i2]) {
                nums.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] < nums2[i2])  {
                i1++;
            }
            else {
                i2++;
            }
        }
        return(nums);
    }
};
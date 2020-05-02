/*
 *  https://leetcode.com/problems/majority-element/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
    int majorityElement3(vector<int>& nums) {
        int index=0;
        int count=1;
        int size = nums.size();
        for(int i = 1; i < size; i++) {
            count += (nums[index] == nums[i]) ? 1 : -1;
            if(count == 0) {index = i; count=1;}
        }
	    return nums[index];
    }
int majorityElement2(vector<int>& nums) {
	int majority=nums[0];
	int count=1;
	int size = nums.size();
	for(int i = 1; i < size; i++) {
		if(majority != nums[i]) {
			count--;
			if(count==0) {majority=nums[i]; count=1;}
		}
		else count++;
		printf("%d %d %d\n", nums[i], count, majority);
	}
	
	return majority;
}
    int majorityElement1(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for(int i: nums) map[i]++;
        int value = 0;
        int count = 0;
        for(auto m: map) {
            if(m.second>count) {value = m.first; count=m.second;}
        }
        return value;
    }
};
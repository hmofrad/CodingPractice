/*
 *	https://leetcode.com/problems/find-the-duplicate-number/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()>1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow!=fast) {
                printf("1.%d %d\n", slow, fast);
                slow=nums[slow];
                fast=nums[nums[fast]];
            }
            fast=0;
            while(fast!=slow) {
                printf("2.%d %d\n", slow, fast);
                fast=nums[fast];
                slow=nums[slow];
            }
            return slow;
        }
        return -1;
    }
    int findDuplicate3(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 1; i < size; i++) {
            if(nums[i-1]==nums[i]) return nums[i];
        }
        return -1;
    }
    int findDuplicate2(vector<int>& nums) {
        std::unordered_set<int> set;
        for(int n: nums) {
            if(not set.insert(n).second) return n;
        }
        return -1;
    }
    int findDuplicate1(vector<int>& nums) {
std::sort(nums.begin(), nums.end());
   // print(nums);

    int begin = 0;
    int end = nums.size()-1;
    
    while(begin <= end) {
        int mid = (begin + end) / 2;
        if(nums[mid] == mid + 1) {
            if(nums[mid] == nums[mid+1]) {
                return(nums[mid]);
            }
            else {
                begin = mid + 1;
            }
        }
        else if(nums[mid] < mid + 1) {
            end = mid - 1;
        }
        else if(nums[mid] > mid + 1) {
            begin = mid + 1;
        }
        
    }
    
    return(nums[begin]);
    }
};
/*
 *	https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       std::set<int> my_set(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<int> dups;
        for(int i = 1; i <= n; i++) {
            if(my_set.count(i)==0) dups.push_back(i);
        }
        return dups;
    }
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        std::vector<int> dups;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            //if(nums[abs(nums[i])-1]<0) dups.push_back(abs(nums[i]));
            //else
                if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1] *= -1;
        }
        
        for(int i = 0; i < size; i++) {
           // printf("%d ", nums[i]);
            if(nums[i]>0) dups.push_back(i+1);
        }
        printf("\n");
        return dups;
    }
};
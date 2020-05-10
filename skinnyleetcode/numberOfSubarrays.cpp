/*
 *	https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/508217/C%2B%2B%3A-Visual-explanation.-O(1)-space.-Two-pointers*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        int j = 0;
        int nodds = 0;
        int count = 0;
        int total = 0;
        for(int i = 0; i < size; i++) {
            if(nums[i]%2) {
                nodds++;
                if(nodds>=k) {
                    count=1;
                    while(not (nums[j++]%2)) count++;
                    total += count;
                }
            }
            else if(nodds>=k) total+=count;
        }
        return total;
    }
    int numberOfSubarrays1(vector<int>& nums, int k) {
        for(int& n: nums) {
            if(n%2) n=1;
            else n=0;
        }
        for(int& n: nums) {
            printf("%d ", n);
        }
        printf("\n");
        int size = nums.size();
        std::vector<int> sums(size);
        sums[0]=nums[0];
        for(int i = 1; i < size; i++) {
            sums[i]+=sums[i-1]+nums[i];
        }
        for(int& n: sums) {
            printf("%d ", n);
        }
        printf("\n");
        
        return 0;
    }
};
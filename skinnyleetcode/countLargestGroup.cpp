/*
 *  https://leetcode.com/problems/count-largest-group/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    int countLargestGroup(int n) {
        std::unordered_map<int, int> nums;
        std::unordered_map<int, std::vector<int>> sums;
        
        for(int i = 0; i <= n; i++) {
            int m = i;
            int s = 0;
            while(m) {
                s += m%10;
                m /= 10;
                if(nums.count(m)) {
                    s+=nums[m];
                    break;
                }
            }
            nums[i] = s;
            sums[s].push_back(i);
        }
        
        
    
        int largest_size = 0;
        for(auto sum: sums) {
            if(sum.second.size() > largest_size and sum.first) largest_size = sum.second.size();
            /*
            printf("%d: ", sum.first);
            for(auto s: sum.second)
                printf("%d ", s);
            printf("\n");
            */
            //size += sum.second.size();
        }
        int size = 0;
        for(auto sum: sums) {
            if(sum.second.size() == largest_size and sum.first) size++;
        }
        
        return(size);
    }
};
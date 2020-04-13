/*
 *  https://leetcode.com/problems/permutations/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::vector<int>> permute1(std::vector<int> nums) {
        //if(nums.empty()) {std::vector<std::vector<int>> temp(1,std::vector<int>()); return temp;}
        if(nums.empty()) {return std::vector<std::vector<int>> (1,std::vector<int>());}
        
        std::vector<std::vector<int>> perms;
        int first = nums[0];
        nums.erase(nums.begin());
        
        std::vector<std::vector<int>> perms1 = permute1(nums);
        //printf("%d\n", perms1.size());
        for(std::vector<int> perm: perms1) {
            int size = perm.size();
            for(int i = 0; i <= size; i++) {
                //printf("%d %d\n", i, first);
                std::vector<int> p;
                p.insert(p.begin(),perm.begin(), perm.begin()+i);
                p.push_back(first);
                p.insert(p.end(), perm.begin()+i, perm.end());
                perms.push_back(p);
            }
        }
        return(perms);
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> perms = permute1(nums);
        return(perms);
    }
};
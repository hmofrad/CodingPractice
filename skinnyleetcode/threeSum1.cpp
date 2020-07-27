/*
 * https://leetcode.com/problems/3sum/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<std::vector<int>> two_sum(vector<int>& nums, int target, int start) {
        std::vector<std::vector<int>> ans;
        int size = nums.size();
        int left = start;
        int right = size-1;
        while(left<right) {
            int sum = nums[left]+nums[right];
            if(sum < target or (left>start and nums[left-1]==nums[left])) { left++; }
            else if(sum > target or (right<size-1 and nums[right]==nums[right+1])){ right--; }
            else { ans.push_back({nums[left++], nums[right--]}); }
        }
        return ans;
    }
    
    std::vector<std::vector<int>> k_sum(vector<int>& nums, int target, int start, int k) {
        std::vector<std::vector<int>> ans;
        int size = nums.size();
        if(start == size) { return ans; }
        if(k==2) { return two_sum(nums, target, start); }
        
        for(int i = start; i < size; i++) {
            if(i==start or nums[i-1]!=nums[i]) {
                std::vector<std::vector<int>> temp = k_sum(nums, target-nums[i], i+1, k-1);
                for(std::vector<int>& t: temp) {
                    t.push_back(nums[i]);
                    ans.push_back(t);
                    
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return k_sum(nums, 0, 0, 3);
    }
};












class Solution2 {
public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        std::set<std::pair<int, int>> found;
        
        for(int i = 0; i < size; i++) {
            std::unordered_set<int> seen;
            for(int j = i+1; j < size; j++) {
                int complement = -nums[i]-nums[j];
                //printf("%d %d\n", complement, seen.count(complement));
                if(seen.count(complement)) {
                    int v1 = min({nums[i], complement, nums[j]});
                    int v2 = max({nums[i], complement, nums[j]});
                    if(found.insert({v1, v2}).second) ans.push_back({nums[i], complement, nums[j]});
                }
                seen.insert(nums[j]);
            }
        }
        
        return ans;
    }
    

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < size-2; i++) {
            if(i==0 or (i and nums[i]!=nums[i-1])) {
                int left = i+1;
                int right = size-1;
                //int sum = 0;
                while(left < right) {
                    int sum = nums[i]+nums[left]+nums[right];
                    if(sum==0) {
                        ans.push_back({nums[i], nums[left], nums[right]});
                        while(left<right and nums[left]==nums[left+1]) left++;
                        left++;
                        while(left<right and nums[right]== nums[right-1]) right--;
                        right--; 
                    }
                    else if(sum<0) left++;
                    else right--;
                }
            }
        }
        
        
        return ans;
        //nums={1,2,3};
        //std::vector<bool> visited(3);
        //vector<vector<int>> ans = backtrack(nums, visited, 0, std::vector<int>(), 3);
        ////vector<vector<int>> ans = comb(nums);
        //for(auto a: ans) printf("%d %d %d\n", a[0], a[1], a[2]);
    }
    
    
    std::vector<std::vector<int>> comb(std::vector<int> nums) {
        //printf("%d %d %d\n",nums.size(), temp.size(), n);
        std::vector<std::vector<int>> ans;
        if(nums.empty()) { ans.push_back(std::vector<int>()); return ans;}
        
        //if(temp.size()==n) {
          //  ans.push_back(temp);
            //return ans;
        //}
        
        int front = nums.front();
        nums.erase(nums.begin());
        std::vector<std::vector<int>> temp0 = comb(nums);
        
        for(std::vector<int>& t: temp0) {
            for(int i = 0; i <= t.size(); i++) {
                std::vector<int> tt(t.begin(), t.begin()+i);
                tt.push_back(front);
                tt.insert(tt.end(), t.begin()+i, t.end());
                ans.push_back(tt);
                //std::vector<std::vector<int>> temp1 = comb(nums, tt, n);
                //ans.insert(ans.end(), temp1.begin(), temp1.end());
            }
        }
        return ans;
    }
    
    std::vector<std::vector<int>> backtrack(std::vector<int>& nums, std::vector<bool> visited, int index, std::vector<int> temp, int n) {
        printf("index=%d\n", index);
        std::vector<std::vector<int>> ans;
        if(temp.size()==n) {
            printf("<%d %d %d>\n", temp[0], temp[1], temp[2]);
            ans.push_back(temp);
            return ans;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) continue;
            temp.push_back(nums[i]);    
            visited[i]=true;
            std::vector<std::vector<int>> temp0 = backtrack(nums, visited, index+1, temp, n);
            ans.insert(ans.end(), temp0.begin(), temp0.end());
            temp.pop_back();
            visited[i]=false;
        }
        return ans;
    }
};
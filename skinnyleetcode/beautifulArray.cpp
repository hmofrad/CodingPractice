/*
 *  https://leetcode.com/problems/beautiful-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> beautifulArray(int N) {
        std::vector<int> ans = {1};
        while(ans.size() < N) {
            std::vector<int> temp;
            for(int i: ans) if(i*2-1<=N) temp.push_back(i*2-1);
            for(int i: ans) if(i*2<=N) temp.push_back(i*2);
            ans=temp;
        }
        return ans;
    }
    
    bool check(std::vector<int>& current) {
        int size =current.size();
        for(int i = 0; i < size-2; i++) 
            for(int k = i+1; k < size-1; k++) 
                for(int j = k+1; j < size; j++) 
                    if(2*current[k] == current[i] + current[j]) return false;
        return true;
    }
    std::vector<int> beauty;
    std::vector<std::vector<int>> dfs(std::vector<int>& nums, std::vector<int> current, int N) {
        std::vector<std::vector<int>> ans;
        if(nums.empty()) {ans.push_back(std::vector<int>()); return ans;}
        if(current.size() == N) {ans.push_back(current); return ans;}
        int first = nums[0];
        nums.erase(nums.begin());
        std::vector<std::vector<int>> temp = dfs(nums, current, N);
        for(std::vector<int> t: temp) {
            int size = t.size();
            for(int i = 0; i <= size; i++) {
                std::vector<int> t1(t.begin(), t.begin()+i);
                t1.push_back(first);
                t1.insert(t1.end(), t.begin()+i, t.end());
                
                if(t1.size() == N) {
                    if(check(t1)) {
                        beauty = t1;
                        return ans;
                    }
                }
                ans.push_back(t1);
                
            }
        }
        return ans;
    }
    vector<int> beautifulArray1(int N) {
        std::vector<int> nums(N);
        for(int i = 1; i <= N; i++) nums[i-1]=i;
        
        std::vector<std::vector<int>> perms = dfs(nums, std::vector<int>(), N);
        
        //for(std::vector<int>& p: perms) {
        //    for(int v: p) printf("%d ", v); printf("\n");
        //}
        
        return beauty;
    }
};
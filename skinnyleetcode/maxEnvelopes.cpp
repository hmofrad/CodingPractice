/*
 * https://leetcode.com/problems/russian-doll-envelopes/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int dfs(vector<vector<int>>& envelopes, int index, int width, int height) {
        int size = envelopes.size();
        if(index == size) { return 0; }
        
        int w = envelopes[index][0];
        int h = envelopes[index][1]; 
        int c1 = (w>width and h>height) ? dfs(envelopes, index+1, w, h) + 1 : INT_MIN;
        int c2 = dfs(envelopes, index+1, width, height);
        
        return max(c1, c2);
    }
    
    int russain_doll(vector<vector<int>>& envelopes) {
        int width = envelopes.front()[0];
        int height = envelopes.front()[1];
        int count = 1;
        int size = envelopes.size();
        for(int i = 1; i < size; i++) {
            int w = envelopes[i][0];
            int h = envelopes[i][1];
            //printf("(%d %d) | (%d %d)\n", width, height, w, h);
            if(w>width and h>height) {
                width=w; height=h;
                count++;
            }
        }
        return count;
    }
    
    /*
    void binary_search(std::vector<int>& dp, int& size, int num) {
        int left = 0;
        int right = size;
        while(left<right) {
            int mid = left + (right-left)/2;
            if(dp[mid]<num) { left = mid+1; }
            else { right = mid-1; }
        }
        dp[left]=num;
        size += (left==size) ? 1 : 0;
    }
    
    int dynamic_program(vector<vector<int>>& envelopes) {
        std::vector<int> dp(envelopes.size());
        int size = 0;
        for(std::vector<int>& e: envelopes) {
            int w = e[0];
            int h = e[1];
            binary_search(dp, size, h);
            for(int d: dp) printf("%d ", d); printf("\n");
        }
        
        return size;
    }
    */

    
    
    int dynamic_program(vector<vector<int>>& envelopes) {
        std::vector<int> dp;//(envelopes.size());
        int size = 0;
        for(std::vector<int>& e: envelopes) {
            int w = e[0];
            int h = e[1];
            auto iter = lower_bound(dp.begin(), dp.end(), h);
            if(iter == dp.end()) { dp.push_back(h); }
            else  { *iter = h; }
        }
        
        return dp.size();
    }

    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //envelopes = {{1,15},{7,18},{7,6},{7,100},{2,200},{17,30},{17,45},{3,5},{7,8},{3,6},{3,10},{7,20},{17,3},{17,45}}; //3
        //envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}}; //5
        if(envelopes.empty()) { return 0; }
        std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
                    
        //for(std::vector<int>& e: envelopes) { printf("(%d %d) ", e[0], e[1]); } printf("\n");
        return dynamic_program(envelopes);
        //return russain_doll(envelopes);
        //return dfs(envelopes, 0, INT_MIN, INT_MIN);
    }
};
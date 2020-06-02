/*
 *  https://leetcode.com/problems/maximum-length-of-pair-chain/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](std::vector<int> a, std::vector<int> b) { return a[1]<b[1];});
        int size = pairs.size();
        std::vector<int> dp(size,1);
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(pairs[j][1] < pairs[i][0]) dp[i]=max(dp[i], dp[j]+1);
            }
        }
        
        int c = 0;
        for(int d: dp) { c = max(c, d);}
        
        return c;
    }
    int findLongestChain1(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](std::vector<int> a, std::vector<int> b) { return a[1]<b[1];});
        int j = 0;
        int c = 1;
        for(int i = 0; i < pairs.size(); i++) {
            if(pairs[j][1] < pairs[i][0]) {j=i; c++;}
                
                //len++;
            //else {max_len = max(len, max_len); len = 1;}
        }
        //max_len = max(len, max_len);
        return c;
    }
};
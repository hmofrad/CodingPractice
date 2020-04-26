/*
 *  https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        std::vector<std::vector<int>> dp(len1+1, std::vector<int>(len2+1));
        
        dp[0][0]=0;
        for(int i = 1; i <= len1; i++) dp[i][0]=dp[i-1][0]+s1[i-1];
        for(int j = 1; j <= len2; j++) dp[0][j]=dp[0][j-1]+s2[j-1];
        
        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        }
        
        return dp[len1][len2];
    }
    int minimumDeleteSum1(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        std::vector<int> map1(26);
        std::vector<int> map2(26);
        
        for(char c: s1) map1[c-'a']++;
        for(char c: s2) map2[c-'a']++;
        
        int sum=0;
        for(int i = 0; i < 26; i++) {
            //printf();
            if(map1[i] and not map2[i]) {sum += map1[i]*(i+'a'); map1[i]=0;}
            if(map2[i] and not map1[i]) {sum += map2[i]*(i+'a'); map2[i]=0;}
        }
        
        
        
        
        return sum;
    }
};
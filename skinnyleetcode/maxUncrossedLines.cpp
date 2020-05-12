/*
 *	https://leetcode.com/problems/uncrossed-lines/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        std::vector<std::vector<int>> dp(sizeA+1, std::vector<int>(sizeB+1));
        for(int i = 1; i <= sizeA; i++) {
            for(int j = 1; j <= sizeB; j++) {
                if(A[i-1] == B[j-1]) { dp[i][j]=1+dp[i-1][j-1]; }
                else { dp[i][j] = max(dp[i-1][j], dp[i][j-1]); }
            }
        }
        return dp[sizeA][sizeB];
    }
    
    
    std::vector<std::vector<int>> dp;
    int dfs2(vector<int>& A, vector<int>& B, int iA, int iB) {
        int sizeA = A.size();
        int sizeB = B.size();
        if(iA==sizeA or iB==sizeB) return 0;
        if(dp[iA][iB]) return dp[iA][iB];
        
        if(A[iA]==B[iB]) { dp[iA][iB] = 1 + dfs2(A, B, iA+1, iB+1); }
        else { dp[iA][iB] = max(dfs2(A, B, iA+1, iB), dfs2(A, B, iA, iB+1)); }
        return dp[iA][iB];    
    }
    
    int maxUncrossedLines2(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        dp.resize(sizeA);
        for(int i = 0; i < sizeA; i++) dp[i].resize(sizeB); 
        
        return dfs2(A, B, 0, 0);   
    }
    
    int dfs1(vector<int>& A, vector<int>& B, int iA, int iB, int crosses) {
        int sizeA = A.size();
        int sizeB = B.size();
        if(iA==sizeA or iB==sizeB) return crosses;
        int gain = (A[iA]==B[iB]) ? 1 : 0;
        return max({dfs1(A, B, iA+1, iB+1, crosses+gain), dfs1(A, B, iA+1, iB, crosses), dfs1(A, B, iA, iB+1, crosses)});
    }
    
    int maxUncrossedLines1(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        return dfs1(A, B, 0, 0, 0);   
    }
};

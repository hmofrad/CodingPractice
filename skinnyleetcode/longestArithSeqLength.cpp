/*
 *	https://leetcode.com/problems/longest-arithmetic-sequence/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
@StayingFoolish This is the explanation you were looking for(Thanks to @saket4) ::-
The main idea is to maintain a map of differences seen at each index.

We iteratively build the map for a new index i, by considering all elements to the left one-by-one.
For each pair of indices (i,j) and difference d = A[i]-A[j] considered, we check if there was an existing chain at the index j with difference d already.

If yes, we can then extend the existing chain length by 1.
Else, if not, then we can start a new chain of length 2 with this new difference d and (A[j], A[i]) as its elements.
At the end, we can then return the maximum chain length that we have seen so far.
*/
class Solution {
public:
    
    int longestArithSeqLength(vector<int>& A) {
        int size = A.size();
        std::unordered_map<int, unordered_map<int, int>> dp;
        int res = 2;
        
        for(int i = 0; i < size; i++) {
            for(int j = i+1; j < size; j++) {
                int d = A[j]-A[i];
                dp[d][j]=dp[d].count(i) ? dp[d][i]+1 : 2;
                res = max(res, dp[d][j]);
            }
        }
        return res;
    }
    
    
    int max_len = INT_MIN;
    void backtrack(std::vector<int>& A, int index, std::vector<int> temp) {
        int size = A.size();
        if(index == size) {
            int sz = temp.size();
            if(sz > max_len) max_len = sz;
            return;
        } 
        
        for(int i = index; i < size; i++) {
            temp.push_back(A[i]);
            int sz = temp.size();
            bool pushed = false;
            if(sz>=3) {
                int diff  = temp[sz-1]-temp[sz-2];
                int diff1 = temp[sz-2]-temp[sz-3];
                if(diff != diff1)  { temp.pop_back();}
            }

            backtrack(A, i+1, temp); 
            if(not temp.empty()) { temp.pop_back();}
        }
    }
    int longestArithSeqLength1(vector<int>& A) {
        backtrack(A, 0, std::vector<int>());
        return max_len;
    }
};
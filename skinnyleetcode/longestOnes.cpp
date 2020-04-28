/*
 *  https://leetcode.com/problems/max-consecutive-ones-iii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int longestOnes1(vector<int>& A, int K) {
        int len = A.size();
        int i =0 ,j = 0;
        for(i = 0; i < len; i++) {
            if(A[i]==0) K--;
            if(K<0) if(A[j++]==0) K++; 
        }
        return i-j;
    }
    int longestOnes(vector<int>& A, int K) {
        int len = A.size();
        int nones=0;
        int nzeros=0;
        int maxflips=0;
        int j = 0;
        for(int i = 0; i < len; i++) {
            //printf("i=%d j=%d nz=%d no=%d max=%d\n", i, j, nzeros, nones, maxflips);
            if(A[i]) nones++;
            else nzeros++;
                
            if(nzeros<=K) maxflips=max(maxflips, nones+nzeros);
            else {
                if(A[j++]==1) nones--;
                else nzeros--;
            }
            
        }
        return maxflips;
    }
};
/*
 *  https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int find(std::vector<int> sum, int L, int M) {
        int maxSumL=sum[L];
        int maxSumLM=sum[L+M];
        int size = sum.size();
        for(int i=L+M+1; i < size; i++) {
            int curSumL=sum[i-M]-sum[i-M-L];
            int curSumM=sum[i]-sum[i-M];
            maxSumL=max(maxSumL, curSumL);
            maxSumLM=max(maxSumLM, maxSumL+curSumM);
        }
        return maxSumLM;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int size = A.size();
        std::vector<int> sum(size+1);
        for(int i=0; i < size; i++) {
            sum[i+1] += sum[i]+A[i];
        }
        return max(find(sum, L, M), find(sum, M, L));
    }
};
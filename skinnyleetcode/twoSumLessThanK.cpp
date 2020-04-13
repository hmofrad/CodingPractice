/*
 *  https://leetcode.com/problems/two-sum-less-than-k/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int twoSumLessThanK1(vector<int>& A, int K) {
        int twoSum = -1;
        int size = A.size();
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                int S = A[i]+A[j];
                if(S < K) {twoSum = max(twoSum, S);}
            }
        }
        return twoSum;
    }
    int twoSumLessThanK(vector<int>& A, int K) {
        int twoSum = -1;
        int size = A.size();
        std::sort(A.begin(), A.end());
        int left = 0;
        int right = size-1;
        while(left < right) {
            int S = A[left] + A[right];
            if(S >= K) {
                right--;
            }
            else {
                left++;
                twoSum = max(twoSum, S);
            }
            
        }
        return twoSum;
    }
};
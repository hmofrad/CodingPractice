/*
 *	https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int size = A.size();
        int sum = std::accumulate(A.begin(), A.end(), 0);
        int avg = sum/3;
        int s = 0;
        int c = 0;
        for(int& a: A) {
            s+=a;
            if(s==avg) {s=0;c++;}
        }
        return c>=3 and sum%3==0;
    }
    bool canThreePartsEqualSum1(vector<int>& A) {
        int size = A.size();
        int sum = std::accumulate(A.begin(), A.end(), 0);
        if(sum%3 != 0) return false;
        int sum3 = sum ? sum/3 : 0;
        
        int s = 0;
        int c = 3;
        for(int i = 0; i < size; i++) {
            s+=A[i];
            if(s==sum3) {s=0; c--;}
        }
        return s ? false : c>0 ? false : true;
    }
};
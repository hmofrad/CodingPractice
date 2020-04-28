/*
 *  https://leetcode.com/problems/monotonic-array/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isMonotonic1(vector<int>& A) {
        bool increasing = true;
        bool decreasing = true;
        int size = A.size();
        for(int i = 0; i < size-1; i++) {
            increasing = A[i]>A[i+1] ? false : increasing;
            decreasing = A[i]<A[i+1] ? false : decreasing;
        }
        return increasing or decreasing;
    }
    bool isMonotonic(vector<int>& A) {
        if(A.size() <= 1) return true;
        int size = A.size();
        int sign = A[0]-A[1];
        for(int i = 1; i < size-1; i++) {
            int diff = A[i]-A[i+1];
            if(sign == 0) {
                sign=diff;
            }
            else {
                if((sign<0 and diff>0) or (sign>0 and diff<0)) return false;
            }
        }
        return true;
    }
};
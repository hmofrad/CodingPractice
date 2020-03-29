/*
 *  https://leetcode.com/problems/fixed-point/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int fixedPoint1(vector<int>& A) {
        int m = A.size();
        int index = -1;
        for(int i = 0; i < m; i++) {
            if(A[i] == i) {
                index = i;
                break;
            }
        }
        return(index);
    }
    
    
    int fixedPoint(vector<int>& A) {
        int m = A.size();
        int left = 0;
        int right = m-1;
        int index = -1;
        while(left <=right) {
            int mid = left + (right-left)/2;
           // printf("%d %d A[%d]=%d\n", left, right, mid, A[mid]);
            if(A[mid] < mid) left = mid+1;
            else if(A[mid] > mid) right = mid-1;
            else {index = mid; right=mid-1;}
        }
        return(index);
    }
    
};
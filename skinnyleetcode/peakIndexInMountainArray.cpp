/*
 *  https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0;
        int high = A.size()-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(A[mid] < A[mid+1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    
    int peakIndexInMountainArray1(vector<int>& A) {
        int index = -1;
        bool peak = false;
        for(int i = 0; i < A.size()-1; i++) {
            //if(not peak) {
                if(not(A[i] < A[i+1])) {
                    index = i;
                    break;
                }
            /*
            }
            else {
                
            }
            */
        }
        return(index);
    }
};
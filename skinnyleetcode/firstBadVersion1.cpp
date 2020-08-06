/*
 * https://leetcode.com/problems/first-bad-version/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(isBadVersion(mid) == true) { right = mid-1; }
            else if(isBadVersion(mid) == false) {  left = mid+1;  }
        }
        return left;
    }
    
    int firstBadVersion0(int n) {
        int l = 1;
        int r = n;
        int mid = n/2;
        while(l <= r) {
            mid = l + (r - l)/2;
            //printf("%d %d %d\n", l, r, mid);
            if(isBadVersion(mid)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return(r+1);
    }
};
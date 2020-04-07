/*
 *  https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = INT_MAX;
        int mid = 0;
        int ret = -1;
        while(left <= right) {
            mid = left + (right-left)/2;
            int val = reader.get(mid);
            //printf("[%d %d %d] %d ? %d\n", left, mid, right, val, target);
            if(val == INT_MAX) {
                right = mid-1;
            }
            else {
                if(target > val) left = mid+1;
                else if(target < val) right = mid-1;
                else {ret = mid; break;}
            }
        }
        return(ret);
    }
};
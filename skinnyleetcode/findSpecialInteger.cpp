/*
 *  https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.empty()) return 0;
        int count = 0;
        int size = arr.size();
        for(int i = 0; i < size-1; i++) {
            if(arr[i] == arr[i+1]) count++;
            else {
                if(count >= size/4) return arr[i]; 
                else count = 0;
            }
        }
        return count >= size/4 ? arr.back() : 0;
    }
};
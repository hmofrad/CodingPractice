/*
 *	https://leetcode.com/problems/max-chunks-to-make-sorted/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int size = arr.size();
        int max = 0;
        int cnt = 0;
        for(int i = 0; i < size; i++) {
            max=std::max(max, arr[i]);
            if(max==i)cnt++;
        }
        return cnt;
    }
};
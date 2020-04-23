/*
 *  https://leetcode.com/problems/rank-transform-of-an-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::vector<int> arr1 = arr;
        std::sort(arr1.begin(), arr1.end());
        std::unordered_map<int, int> sorted;
        int i = 1;
        for(int a: arr1) {
            if(not sorted.count(a)) {sorted[a]=i; i++;}
        } 
        
        for(int& a: arr) {
            a=sorted[a];
        }
        return arr;
    }
};
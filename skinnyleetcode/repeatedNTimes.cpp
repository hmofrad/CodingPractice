/*
 *  https://leetcode.com/problems/n-repeated-element-in-size-2n-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int m = A.size();
        int n = m/2;
        std::unordered_map<int, int> map;
        for(auto a :A){
            if(++map[a]>1) return(a);
        }
        return(-1);
    }
};
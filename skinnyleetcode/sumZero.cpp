/*
 *  Problem: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> m(n);
        for(int i = 0; i < n-1; i+=2) {
            m[i] = i+1;
            m[i+1] = -(i+1);
        }
        return(m);
    }
};
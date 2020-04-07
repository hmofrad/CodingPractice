/*
 *  https://leetcode.com/problems/play-with-chips/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        int even = 0;
        for(int chip: chips) {
            if(chip%2) odd++;
            else even++;
        }
        return (odd > even) ? even : odd;
    }
};
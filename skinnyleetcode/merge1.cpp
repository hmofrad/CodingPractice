/*
 * https://leetcode.com/problems/merge-intervals/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {return a[0]==b[0] ? a[1] < b[1] : a[0] < b[0];});
        vector<vector<int>> ans;
        
        for(std::vector<int> interval: intervals) {
            if(ans.empty() or ans.back()[1]<interval[0]) { ans.push_back(interval); }
            else ans.back()[1] = max(ans.back()[1], interval[1]);
        }

        return ans;
    }
};
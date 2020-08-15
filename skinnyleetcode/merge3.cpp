/*
 * https://leetcode.com/problems/merge-intervals/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() or intervals[0].empty()) { return vector<vector<int>>(); }
        int size = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
                  return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        std::vector<std::vector<int>> ans; 
        ans.push_back(intervals.front());
        for(int i = 1; i < size; i++) {
            if(ans.back()[1] >= intervals[i][0]) {
                ans.back() = {min(ans.back()[0], intervals[i][0]), max(ans.back()[1], intervals[i][1])};
            }
            else { ans.push_back(intervals[i]); }
        }
        return ans;
    }
    
    
    vector<vector<int>> merge0(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {return a[0]==b[0] ? a[1] < b[1] : a[0] < b[0];});
        vector<vector<int>> ans;
        
        for(std::vector<int> interval: intervals) {
            if(ans.empty() or ans.back()[1]<interval[0]) { ans.push_back(interval); }
            else ans.back()[1] = max(ans.back()[1], interval[1]);
        }

        return ans;
    }
    
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        if(intervals.empty()) { return vector<vector<int>>(); }
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) { return a[0]==b[0] ? a[1]<b[1] : a[0]<b[0]; });
        vector<vector<int>> ans;
        ans.push_back(intervals.front());
        int size = intervals.size();
        for(int i = 1; i < size; i++) {
            if(ans.back()[1]>=intervals[i][0]) { ans.back()[1] = max(ans.back()[1], intervals[i][1]); }
            else { ans.push_back(intervals[i]); }
        }
        return ans;
    }
};
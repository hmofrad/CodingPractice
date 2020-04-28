/*
 *  https://leetcode.com/problems/remove-interval/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        std::vector<std::vector<int>> ans;
        int removeStart = toBeRemoved[0];
        int removeEnd = toBeRemoved[1];
        int nintervals = intervals.size();
        for(int i = 0; i < nintervals; i++) {
            int intervalStart = intervals[i][0];
            int intervalEnd = intervals[i][1];
            if(intervalEnd <= removeStart or intervalStart >= removeEnd) ans.push_back({intervalStart, intervalEnd});
            else {
                if(intervalStart < removeStart) ans.push_back({intervalStart, removeStart});
                if(intervalEnd > removeEnd) ans.push_back({removeEnd, intervalEnd});
            }
        }
        return ans;
    }
    vector<vector<int>> removeInterval2(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        std::vector<std::vector<int>> ans;
        int removeStart = toBeRemoved[0];
        int removeEnd = toBeRemoved[1];
        int nintervals = intervals.size();
        for(int i = 0; i < nintervals; i++) {
            int intervalStart = intervals[i][0];
            int intervalEnd = intervals[i][1];
            if(intervalEnd <= removeStart or intervalStart >= removeEnd) ans.push_back({intervalStart, intervalEnd});
            else if(intervalStart < removeStart and intervalEnd > removeEnd) {
                ans.push_back({intervalStart, removeStart});
                ans.push_back({removeEnd, intervalEnd});
            }
            else if(intervalStart < removeStart and intervalEnd <= removeEnd) ans.push_back({intervalStart, removeStart});
            else if(intervalStart >= removeStart and intervalEnd > removeEnd) ans.push_back({removeEnd, intervalEnd});
        }
        return ans;
    }
        
    vector<vector<int>> removeInterval1(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        std::vector<std::vector<int>> ans;
        int nintervals = intervals.size();
        for(int i = 0; i < nintervals; i++) {
            std::vector<int>& interval = intervals[i];
            int start = max(interval[0], toBeRemoved[0]);
            int end = min(interval[1], toBeRemoved[1]);
            if(start <= interval[0] and end >= interval[1]) ;
            else if(start > interval[0] and end >= interval[1]) ans.push_back({interval[0], start});
            else if(start <= interval[0] and end < interval[1]) ans.push_back({end, interval[1]});
            else {
                if(interval[0] < start) ans.push_back({interval[0], start});
                if(interval[1] > end) ans.push_back({end, interval[1]});
                if((interval[0] > start and interval[1] > end) or 
                   (interval[0] < start and interval[1] < end)) ans.push_back(interval);
            }
        }
        return ans;
    }
};
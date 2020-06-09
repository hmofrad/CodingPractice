/*
 * https://leetcode.com/problems/insert-interval/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //intervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
        //newInterval={4,8};
        std::vector<std::vector<int>> intervals1;
        if(intervals.empty()) {intervals1.push_back(newInterval); return intervals1;}
        
        if(newInterval[1] < intervals.front()[0]) {
            intervals.insert(intervals.begin(), 1, newInterval);
            //intervals1.push_back(newInterval); 
            //intervals1.insert(intervals1.end(), intervals.begin(), intervals.end());
            return intervals;
        }
        else if(intervals.back()[1]<newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
                
        }

        int size = intervals.size();
        for(int i = 0; i < size; i++) {
            std::vector<int>& interval = intervals[i];
            if(i == 0 or (intervals1.back()[1] < interval[0])) {
                intervals1.push_back(interval);
            } 
            else { intervals1.back()={min(intervals1.back()[0], interval[0]), max(intervals1.back()[1], interval[1])}; }
            if(not newInterval.empty() and (intervals1.back()[1] >= newInterval[0] and newInterval[1] >= intervals1.back()[0])) {
                intervals1.back()={min(intervals1.back()[0], newInterval[0]), max(intervals1.back()[1], newInterval[1])};
                newInterval.clear();
                //printf("i=%d %d %d\n", i, intervals1.back()[0], intervals1.back()[1]);
            }
        }
        
        if(not newInterval.empty()) {
        //    printf("xxx\n");
            int i = 0;
            for(; i < intervals1.size()-1; i++) {
                if(newInterval[0] > intervals1[i][1] and newInterval[1] < intervals1[i+1][0]) break;
            }
            intervals1.insert(intervals1.begin()+i+1, 1, newInterval);
            
            intervals = intervals1;
            intervals1.clear();
            int size = intervals.size();
            for(int i = 0; i < size; i++) {
                std::vector<int>& interval = intervals[i];
                if(i == 0 or (intervals1.back()[1] < interval[0])) { intervals1.push_back(interval); } 
                else { intervals1.push_back({intervals1.back()[0], interval[1]}); }
            }
        }
        
        
        return intervals1;
    }
};
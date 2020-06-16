/*
 * https://leetcode.com/problems/meeting-rooms-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        std::vector<int> start, end;
        for(int i = 0; i < size; i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        
        std::sort(start.begin(), start.end());
        std::sort(end.begin(), end.end());
        
        int count=0, j=0;
        for(int i = 0; i < size; i++) {
            if(start[i]<end[j]) count++;
            else j++;
        }
        return count;
    }
    int minMeetingRooms1(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) { 
        return a[0]==b[0] ? a[1] < b[1] : a[0] < b[0]; });
        std::map<int, int> map;
        int size = intervals.size();
        int count = 0; 
        int time = 0;
        for(int i = 0; i < size; i++) {
            map[intervals[i][0]]++;
            map[intervals[i][1]]--;
        }
        
        int c = 0;
        for(auto m: map) {
            c += m.second;
            count = max(count, c);
        }
        
        return count;
    }
};
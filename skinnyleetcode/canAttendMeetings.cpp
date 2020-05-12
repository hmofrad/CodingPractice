/*
 *	https://leetcode.com/problems/meeting-rooms/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canAttendMeetings2(vector<vector<int>>& intervals) {
        int size = intervals.size();
        for(int i = 0; i < size-1; i++) {
            int si = intervals[i][0];
            int ei = intervals[i][1];
            for(int j = i+1; j < size; j++) {
                int sj = intervals[j][0];
                int ej = intervals[j][1];
                int smax  = max(si, sj);
                int emin = min(ei, ej);
                if(emin>smax) return false;
            }
        }
        return true;
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int size = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int> b) {return a[0]==b[0] ? a[1]<b[1] : a[0]<b[0];});
        for(int i = 0; i < size-1; i++) {
            if(intervals[i+1][0] < intervals[i][1]) return false;
        }
        return true;
    }
    bool canAttendMeetings1(vector<vector<int>>& intervals) {
        if(intervals.empty()) return true;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int> b) {return a[0]==b[0] ? a[1]<b[1] : a[0]<b[0];});
        int size = intervals.size();
        int s = intervals[0][0];
        int e = intervals[0][1];
        bool could = true;
        for(int i = 1; i < size; i++) {
            int si = intervals[i][0];
            int ei = intervals[i][1];
            
            if(si<e)  {could = false; break;}
            s=min(s,si);
            e=max(e, ei);
            
        }
        return could;
    }
};
int main() {
	std::vector<std::vector<int>> intervals = {{1,13},{13,15}};
	bool b = canAttendMeetings(intervals);
	printf("B=%d\n", b);
	return 0;
}
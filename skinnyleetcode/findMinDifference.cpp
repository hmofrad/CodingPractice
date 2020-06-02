/*
 *  https://leetcode.com/problems/minimum-time-difference/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        std::sort(timePoints.begin(), timePoints.end());
        int min_diff = INT_MAX;
        int size = timePoints.size();
        for(int i = 0; i < size; i++) {
            int h0 = (timePoints[(i-1+size)%size][0]-'0')*10 + (timePoints[(i-1+size)%size][1]-'0');
            int m0 = (timePoints[(i-1+size)%size][3]-'0')*10 + (timePoints[(i-1+size)%size][4]-'0');
            int h1 = (timePoints[i][0]-'0')*10 + (timePoints[i][1]-'0');
            int m1 = (timePoints[i][3]-'0')*10 + (timePoints[i][4]-'0');
            int diff = abs((h0-h1)*60 + (m0-m1));
            min_diff = min({min_diff, diff, 1440-diff});
        }
        return min_diff;
    }
};
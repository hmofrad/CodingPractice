/*
 *	https://leetcode.com/problems/teemo-attacking/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int size = timeSeries.size();
        int poisened = 0;
        for(int i = 0; i < size-1; i++) {
            poisened += min(timeSeries[i+1]-timeSeries[i], duration);
        }
        return poisened + duration;
    }
};
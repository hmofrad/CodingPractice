/*
 *	https://leetcode.com/problems/distance-between-bus-stops/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int start1 = min(start, destination);
        int destination1 = max(start, destination);
        int total = 0;
        int dist = 0;
        for(int i = 0; i < n; i++) {
            total += distance[i];
            if(i>=start1 and i<destination1) dist+=distance[i];
        }
        return min(dist, total-dist);
    }
};
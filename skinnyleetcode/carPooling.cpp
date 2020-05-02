/*
 *  https://leetcode.com/problems/car-pooling/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::map<int, int> capacities;
        for(std::vector<int>& trip: trips) {
            int npassengers = trip[0];
            int start_location = trip[1];
            int end_location = trip[2];
            capacities[start_location] +=npassengers;
            capacities[end_location] -= npassengers;
        }
        
        for(auto& c: capacities) {
            capacity -= c.second;
            if(capacity<0) return false;    
        }
        return true;
    }
    /*
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(), [](std::vector<int>& a, std::vector<int>& b) {return a[1]==b[1] ? a[2]<b[2] : a[1]<b[1];});
        int cap = 0;
        int start = 0;
        int end = INT_MAX;
        std::map<int, int> caps;
        for(std::vector<int>& trip: trips) {
            int npassengers = trip[0];
            int start_location = trip[1];
            int end_location = trip[2];
            int current_start=max(start, start_location);
            int current_end=min(end, end_location);
            caps[current_start]=npassengers;
            caps[current_end]=npassesngers;
            if(current_start <= end and current_end >= start) {cap += npassengers; if(cap>capacity) return false;}
            else {cap=npassengers;}
        }
        return true;
    }
    */
};
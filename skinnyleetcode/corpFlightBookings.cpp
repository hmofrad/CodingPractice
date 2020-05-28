/*
 *	https://leetcode.com/problems/corporate-flight-bookings/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        std::vector<int> ans(n);
        for(std::vector<int>& itinerary: bookings) {
            int src = itinerary[0];
            int dst = itinerary[1];
            int seats = itinerary[2];
            ans[src-1] += seats;
            if(dst<n) ans[dst]-=seats;
        }
        for(int i = 1; i < n; i++) ans[i] +=ans[i-1];
        return ans;
    }
    vector<int> corpFlightBookings1(vector<vector<int>>& bookings, int n) {
        std::vector<int> ans(n);
        for(std::vector<int>& itinerary: bookings) {
            int src = itinerary[0];
            int dst = itinerary[1];
            int seats = itinerary[2];
            for(int i = src; i <=dst; i++) {
                ans[i-1]+=seats;
            }
        }
        return ans;
    }
};
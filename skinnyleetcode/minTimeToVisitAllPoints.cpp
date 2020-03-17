/*
 *  Problem: https://leetcode.com/problems/minimum-time-visiting-all-points/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int minDist(std::vector<int> v1, std::vector<int> v2) {
        int r = 0;
        int dx = std::abs(v1[0]-v2[0]);
        int dy = std::abs(v1[1]-v2[1]);
        return(std::max(dx, dy));
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int d = 0;
        for(int i = 0; i < points.size()-1; i++) {
            d += minDist(points[i], points[i+1]);
        }
        return(d);
    }
};
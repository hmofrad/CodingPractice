/*
 *  https://leetcode.com/problems/largest-triangle-area/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    //double largestTriangleArea1(vector<vector<int>>& points) {
    //}
    
    
    double eculidean_distance(std::vector<int> p1, std::vector<int> p2) {
        return sqrt(pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int npoints = points.size();
        double a = 0, b = 0, c = 0;
        double area = 0, max_area = 0;
        for(int i = 0; i < npoints; i++) {
            for(int j = i+1; j < npoints; j++) {
                for(int k = j+1; k < npoints; k++) {
                    a = eculidean_distance(points[i], points[j]);
                    b = eculidean_distance(points[j], points[k]);
                    c = eculidean_distance(points[k], points[i]);
                    if(a+b > c and b+c > a and c+a > b) {
                        area = (a+b+c)/2;
                        max_area = max(max_area, sqrt(area*(area-a)*(area-b)*(area-c)));
                    }
                }
            }
        }
        
        
        return max_area;
    }
};
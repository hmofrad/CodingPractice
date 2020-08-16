/*
 * https://leetcode.com/problems/container-with-most-water/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max_area = 0;
        int left = 0;
        int right = size-1;
        while(left<right) {
            int x = right-left;
            int y = min(height[left],height[right]);
            int area = x*y;
            max_area = max(max_area, area);
            if(height[left]<=height[right]) left++;
            else right--;
        }
        return max_area;
    }
    int maxArea1(vector<int>& height) {
        int size = height.size();
        int max_area = 0;
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                int x = j-i;
                int y = min(height[i],height[j]);
                int area = x*y;
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
    int maxArea2(vector<int>& height) {
        if(height.size()<2) { return 0; }
        int size = height.size();
        int il = 0, jl = 0;
        int ir = size-1, jr = size-1;
        int max_area = 0;
        while(il < ir) {
            int area = min(height[jl], height[jr]) * (jr-jl);
            max_area = max(max_area, area);
            //printf("[%d %d %d] [%d %d %d] [%d %d]\n", il, jl, hl, ir, jr, hr, max_area, area);
            if(height[il]<=height[ir]) {
                if(height[il]>height[jl]) { jl = il; }                
                il++;
                if(il < ir and height[il]>height[jl]) { jl = il; }
            }
            else {
                if(height[ir]>height[jr]) { jr = ir; }
                ir--;
                if(ir>il and height[ir]>height[jr]) { jr = ir; }
            }

        }
        return max_area;
    }
};
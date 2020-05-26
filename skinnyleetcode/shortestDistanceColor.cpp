/*
 *	https://leetcode.com/problems/shortest-distance-to-target-color/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int binary_search(std::vector<int>& vec, int value) {
        int d = INT_MAX;
        int left = 0;
        int right = vec.size()-1;
        while(left<=right) {
            int mid = (left+right)/2;
            if(vec[mid]>value) {d=min(d,vec[mid]-value); right=mid-1;}
            else if(vec[mid]<value) {d=min(d,value-vec[mid]); left=mid+1;}
            else {d = 0; break;}
        }
        return d == INT_MAX ? -1 : d;
    }
    int linear_search(std::vector<int>& vec, int value) {
        int d = INT_MAX;
        int s = vec.size();
        for(int i = 0; i < s; i++) { d=min(d, abs(vec[i]-value)); }
        d = d != INT_MAX ? d : -1;
        return d;
    }
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        std::unordered_map<int, std::vector<int>> map;
        int size = colors.size();
        for(int i = 0; i < size; i++) map[colors[i]].push_back(i);
        std::vector<int> ans;
        for(std::vector<int>& query: queries) {
            int index = query[0];
            int color = query[1];
            std::vector<int>& vec = map[color];
            //ans.push_back(linear_search(vec, index));
            ans.push_back(binary_search(vec, index));
        }
        return ans;
    }
};
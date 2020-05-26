/*
 *	https://leetcode.com/problems/minimum-area-rectangle/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int minAreaRect(vector<vector<int>>& points) {
        std::unordered_map<int, std::set<int>> x;
        for(std::vector<int>& point: points) {
            int row = point[0];
            int col = point[1];
            x[row].insert(col);
        }
        int size = points.size();
        int res = INT_MAX;
        for(int i = 0; i < size-1; i++) {
            int ri = points[i][0];
            int ci = points[i][1];
            for(int j = i+1; j < size; j++) {
                int rj = points[j][0];
                int cj = points[j][1];
                if(ri==rj or ci==cj) continue;
                if(x[ri].count(cj) and x[rj].count(ci)) { res = min(res, abs(ri-rj) * abs(ci-cj));}
            }
        }
        return res == INT_MAX ? 0 : res;
    }
    int minAreaRect1(vector<vector<int>>& points) {
        std::unordered_map<int, std::set<int>> x;
        for(std::vector<int>& point: points) {
            int row = point[0];
            int col = point[1];
            x[row].insert(col);
        }
        int res = INT_MAX;
        for(auto i = x.begin(); i != x.end(); i++) {
            for(auto j = std::next(i); j != x.end(); j++) {
                if(i->second.size()<2 or j->second.size()<2) continue; 
                std::vector<int> y;
                std::set_intersection(std::begin(i->second), std::end(i->second), std::begin(j->second), std::end(j->second), back_inserter(y));
                for(int k = 1; k < y.size(); k++) {res=min(res, abs(j->first-i->first) * (y[k]-y[k-1]));}
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
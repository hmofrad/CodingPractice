/*
 * https://leetcode.com/problems/k-closest-points-to-origin/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    double euclidean_distance_to_zero(std::vector<int> a){
        return(a[0]*a[0] + a[1]*a[1]);
    }
    
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int K) {
        std::vector<std::vector<int>> ans;
        std::sort(points.begin(), points.end(), [this](std::vector<int> a, std::vector<int> b){
           return (euclidean_distance_to_zero(a) < euclidean_distance_to_zero(b)); 
        });
        int size = points.size();
        for(int i = 0; i < size and i < K; i++) {
            ans.push_back(points[i]);
        }
        return(ans);
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::vector<double> distances;
        for(std::vector<int>& point: points) {
            distances.push_back(euclidean_distance_to_zero(point));
        }
        
        std::vector<std::pair<int, double>> pairs;
        int size = points.size();
        for(int i = 0; i < size; i++) {
            pairs.push_back({i, distances[i]});
        }
        
        std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, double>& a, const std::pair<int, double>& b) { return a.second > b.second; } );
    
        std::vector<std::vector<int>> ans;
        while(not pairs.empty() and K) {
            ans.push_back(points[pairs.back().first]);
            pairs.pop_back();
            K--;
        }
    return ans;
    }
    
    vector<vector<int>> kClosest3(vector<vector<int>>& points, int K) {
        std::vector<std::vector<int>> ans;
        std::map<double, std::vector<std::vector<int>>> map;
        
        for(std::vector<int> point: points) {
            double d = euclidean_distance_to_zero(point);
            map[d].push_back(point);
        }
        
        bool b = false;
        int s = 0;
        for(auto m: map) {
            std::vector<std::vector<int>> vec = m.second;
            for(std::vector<int> v: vec) {
                if(s < K) {
                    ans.push_back(v);
                    s++;
                }
                else{
                    b = false;
                    break;
                }
            }
            if(b or s >= K) break;
        }
        return(ans);
    }
};
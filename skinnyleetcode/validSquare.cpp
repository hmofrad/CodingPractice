/*
 * https://leetcode.com/problems/valid-square/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    double dist(std::vector<int>& p1, std::vector<int>& p2) {
        return ((p1[0]-p2[0])*(p1[0]-p2[0])) + ((p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    bool validSquare0(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        std::unordered_set<double> s({ dist(p1, p2), dist(p1, p3), dist(p1, p4), dist(p2, p3), dist(p2, p4), dist(p3, p4) });
        return s.count(0) == 0 and s.size() == 2;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        std::vector<std::vector<int>> p;
        p.push_back(p1); p.push_back(p2); p.push_back(p3); p.push_back(p4);
        std::sort(p.begin(), p.end(), [](const std::vector<int>& a, const std::vector<int>& b) { 
            return a[0]==b[0] ? a[1]<b[1] : a[0]<b[0]; 
        });
        
        return dist(p[0], p[1]) != 0 && dist(p[0], p[1]) == dist(p[1], p[3]) && dist(p[1], p[3]) == dist(p[3], p[2]) && dist(p[3], p[2]) == dist(p[2], p[0])   && dist(p[0],p[3])==dist(p[1],p[2]);
                return dist(p[0],p[1]) != 0 and // sides
               dist(p[0],p[1]) == dist(p[1],p[3]) and 
               dist(p[1],p[3]) == dist(p[3],p[2]) and 
               dist(p[3],p[2]) == dist(p[2],p[0]) and 
               dist(p[0],p[3]) == dist(p[1],p[2]); //diagonal
    }
};
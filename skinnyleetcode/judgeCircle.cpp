/*
 *  https://leetcode.com/problems/robot-return-to-origin/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    bool judgeCircle(string moves) {
        std::unordered_map<char, std::pair<int,int>> map;
        map['U'] = std::make_pair(0,+1);
        map['D'] = std::make_pair(0,-1);
        map['L'] = std::make_pair(1,-1);
        map['R'] = std::make_pair(1,+1);
        
        std::vector<int> D(2);
        for(auto move: moves) {
            auto m = map.find(move)->second;
            D[m.first] += m.second;
        }
        return((D[0] == 0) and (D[1] == 0));
    }
};
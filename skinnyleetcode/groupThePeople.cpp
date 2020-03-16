/*
 *  Problem: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> out;
        std::map<int, std::vector<int>> map;
        for(int i = 0; i < groupSizes.size(); i++) {
            map[groupSizes[i]].push_back(i);
            if(map[groupSizes[i]].size() == groupSizes[i]) {
                out.push_back(map[groupSizes[i]]);
                map[groupSizes[i]].clear();
            }
        }
        /*
        int k = 0;
        for(auto m: map) {
            auto& vec = m.second;
            while(not vec.empty()) {
                int i = m.first;
                int j = 0;
                //printf("%d %d\n", i, vec.size());
                out.push_back(std::vector<int>());
                for(auto v: vec) {

                    out.back().push_back(v);
                    j++;
                    if(j>=i) {
                        break;
                    }
                }
                //printf("%d %d %d\n", i, j, vec.size());
                for(; j > 0; j--) {
                    vec.pop_front();
                }
            }
        }
        */
        return(out);
    }
};
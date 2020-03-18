/*
 *  Problem: https://leetcode.com/problems/high-five/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        std::unordered_map<int, std::vector<int>> map;
        for(auto item: items) {
            map[item[0]].push_back(item[1]);
        }
        std::map<int, int> map1;
        for(auto m: map) {
            auto vec = m.second;
            if(vec.size() > 5) {
                std::sort(vec.begin(), vec.end(), [](int a, int b){return(a>b);});
            }    
            map1[m.first] = std::accumulate(vec.begin(), vec.begin()+5, 0)/5;
            
        }
        vector<vector<int>> out;
        for(auto m: map1) {
            out.push_back({m.first, m.second});
            //printf("%d %d\n", m.first, m.second);
        }
        
        
        
        
        return(out);
    }
};
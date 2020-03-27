/*
 *  https://leetcode.com/problems/unique-number-of-occurrences/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> map;
        for(auto a: arr){
            map[a]++;
        }
        bool ret = true;
        std::unordered_map<int, bool> map1;
        for(auto m: map) {
            if(map1.find(m.second) != map1.end()) {
                ret = false;
                break;
            }
            else {
                map1[m.second] = true;
            }
        }
        return(ret);
    }
};
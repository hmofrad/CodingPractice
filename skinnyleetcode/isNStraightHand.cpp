/*
 *	https://leetcode.com/problems/hand-of-straights/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        std::map<int, int> map;
        for(int c: hand) map[c]++;
        while(not map.empty()) {
            auto it = map.begin();
            int first = it->first;
            for(int i = first; i < first+W; i++) {
                if(not map.count(i)) return false;
                map[i]--;
                if(map[i]==0) map.erase(i);
            }
        }
        return true;
    }
};
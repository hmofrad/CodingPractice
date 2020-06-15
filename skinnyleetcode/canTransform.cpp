/*
 * https://leetcode.com/problems/swap-adjacent-in-lr-string/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    bool canTransform(string start, string end) {
        int i = 0;
        int j = 0;
        int len = start.size();
        
        std::string s;
        std::string e;
        while(i<len and j<len) {
            if(start[i]!='X') s.push_back(start[i]);
            if(end[j]!='X') e.push_back(end[j]);
            i++, j++;
        }
        if(s!=e) return false;
        i=0,j=0;
        while(i<len and j<len) {
            if(start[i]=='X') i++;
            else if(end[j]=='X') j++;
            else {
                if((start[i]=='R' and j<i) or (start[i]=='L' and j>i)) return false;
                i++, j++;
            }
        }
        return true;
    }
};
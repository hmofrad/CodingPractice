/*
 *  Problem: https://leetcode.com/problems/single-row-keyboard/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int d_abs(int a, int b) {
        return((a>b) ? a-b : b - a);
    }
    int calculateTime(string keyboard, string word) {
        std::vector<char> keys(26);
        for(int i = 0; i < keyboard.size(); i++){
            keys[keyboard[i]-'a']=i;
        }
            
        int d = 0;
        int cursor = 0;
        for(auto w: word) {
            int current = keys[w-'a'];
             d += d_abs(cursor, current);
             cursor = current;
        }
        return(d);
    }
};
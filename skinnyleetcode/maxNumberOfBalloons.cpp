/*
 *  https://leetcode.com/problems/maximum-number-of-balloons/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        std::vector<int> map(26);
        for(char c: text) {
            map[c-'a']++;
        }
        std::vector<char> balloon = {'b', 'a', 'l', 'o', 'n'};
        std::vector<int> map1(26);
        map1['a'-'a'] = 1; 
        map1['b'-'a'] = 1; 
        map1['l'-'a'] = 2;
        map1['o'-'a'] = 2;
        map1['n'-'a'] = 1;
        
        int mi = INT_MAX;
        for(char c: balloon) {
            int count = map[c-'a'];
            int freq = map1[c-'a'];
            
            mi = (freq) ? min(mi, count/freq) : mi;
            //printf("%c %d %d %d\n", c, count, freq, mi);
        }
        
        return mi != INT_MAX ? mi : 0;
    }
};
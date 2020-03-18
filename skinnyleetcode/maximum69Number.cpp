/*
 *  Problem: https://leetcode.com/problems/maximum-69-number/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        for(auto& c: s) {
            if(c == '6') {
                c = '9';
                break;
            }
        }
        
        return(std::stoi(s));
        
    }
};


/*
 * https://leetcode.com/problems/expression-add-operators/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void recurse( std::vector<std::string>& ans, std::string temp, std::string& num, int& target, int index, long val, long multed) {
        int len = num.length();
        if(index == len) {
            if(target == val) { ans.push_back(temp); }
            return;
        }
        
        for(int i = index; i < len; i++) {
            if(i != index and num[index]=='0') { break; }
            std::string t = num.substr(index, i-index+1);
            long cur = stol(t);
            if(index == 0) { recurse(ans, temp + to_string(cur),  num, target, i+1, cur, cur); }
            else {
                 recurse(ans, temp + '+' + t,  num, target, i+1, val+cur, +cur); 
                 recurse(ans, temp + '-' + t,  num, target, i+1, val-cur, -cur); 
                 recurse(ans, temp + '*' + t,  num, target, i+1, val-multed + multed*cur, multed*cur); 
            }
            
        }
        
    }
    vector<string> addOperators(string num, int target) {
        if(num.length() == 0) { return std::vector<std::string>(); }
        std::vector<std::string> ans;
        recurse(ans, std::string(), num, target, 0, 0, 0);
        return ans;
    }
};
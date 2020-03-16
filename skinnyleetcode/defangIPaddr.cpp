/*
 *  Problem:https://leetcode.com/problems/defanging-an-ip-address/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    string defangIPaddr(string address) {
        std::string defanged_address;
        for(auto c: address){
            if(c == '.') {
                defanged_address += "[.]";
            }
            else {
                defanged_address += c;
            }
        }
        return(defanged_address);
    }
};
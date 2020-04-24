/*
 *  https://leetcode.com/problems/convert-to-base-2/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    std::string base2(int N) {
        std::string ans;
        while(N) {
            ans = to_string(N&1) + ans;
            N = N >> 1;
        }
        return ans.empty() ? "0" : ans; 
    }
    string baseNeg2(int N) {
        std::string ans;
        while(N) {
            ans = to_string(N&1) + ans;
            N = -(N>>1);
        }    
        return ans.empty() ? "0" : ans; 
    }
};
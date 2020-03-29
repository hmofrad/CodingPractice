/*
 *  https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int m = seq.size();
        vector<int> out(m);
        int a_count = 0;
        int b_count = 0;
        for(int i = 0; i < m; i++) {
            char c = seq[i];
            if (c == '(') {
                if (a_count < b_count) {
                    out[i] = 0;
                    a_count++;
                }
                else {
                    out[i] = 1;
                    b_count++;
                }
            } else {
                if (a_count > b_count) {
                    out[i] = 0;
                    a_count--;
                } else {
                    out[i] = 1;
                    b_count--;
                }
            }
        }
        return out;
    }
};
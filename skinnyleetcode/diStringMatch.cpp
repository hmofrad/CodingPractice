/*
 *  https://leetcode.com/problems/di-string-match/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> diStringMatch(string S) {
        if(S.empty()) return {};
        int n = S.length();
        int left = 0;
        int right = n;
        std::vector<int> vec;
        for(int i = 0; i < n; i++) {
            auto& c = S[i];
            if(c == 'I') {
                vec.push_back(left);
                left++;
            }
            else {
                vec.push_back(right);
                right--;
            }
        }
        vec.push_back(left);
        return(vec);
    }
};
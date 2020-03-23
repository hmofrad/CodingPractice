/*
 *  https://leetcode.com/problems/output-contest-matches/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    string findContestMatch(int n) {
        std::vector<std::string> teams(n);
        for (int i = 1; i <= n; i++) {
            teams[i-1] = to_string(i);
        }

        for (; n > 1; n /= 2) {
            for (int i = 0; i < n / 2; i++) {
                teams[i] = '(' + teams[i] + ',' + teams[n-1-i] + ')';
            }
        }

        return(teams[0]);
    }
};
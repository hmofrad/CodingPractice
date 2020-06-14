/*
 * https://leetcode.com/problems/minimum-window-subsequence/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    string minWindow(string S, string T) {
        int i = 0, len_s = S.length();
        int j = 0, len_t = T.length();
        std::string ans;
        while(i<len_s) {
            if(S[i] == T[j]) {
                j++;
                if(j == len_t) {
                    int end = i+1; 
                    j--;
                    while(j>=0) {
                        if(S[i]==T[j]) j--;
                        i--;
                    }
                    i++; j++;
                    std::string temp = S.substr(i, end-i);
                   // printf("[%s] %d\n", temp.c_str(), ans.size());
                    if(ans.empty() or temp.size()<ans.size()) ans = temp;
                }
            }
            i++;
        }
        

        return ans;
    }
};
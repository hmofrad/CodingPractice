/*
 *  https://leetcode.com/problems/letter-case-permutation/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void permute(std::vector<string>& ans, std::string S, std::string temp, int index) {
        int size = S.length();
        if(index == size) {ans.push_back(temp); return;}
        
        
        if((S[index] >= 'a' and S[index] <= 'z') or (S[index] >= 'A' and S[index] <= 'Z')) {
            int i = 0;
            if(S[index] >= 'a' and S[index] <= 'z')
                i = S[index] - 'a';
            else 
                i = S[index] - 'A';
            char c1  = 'a'+i;
            permute(ans, S, temp+c1, index+1);
            char c2 = 'A'+i;;
            permute(ans, S, temp+c2, index+1);
        }
        else {
            char c  = S[index];
            permute(ans, S, temp+c, index+1);
        }
        
    }
    vector<string> letterCasePermutation(string S) {
        std::vector<string> ans;
        std::string temp;
        int index = 0;
        permute(ans, S, temp, 0);
        return(ans);
    }
};
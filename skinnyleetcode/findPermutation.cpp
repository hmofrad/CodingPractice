/*
 *  https://leetcode.com/problems/find-permutation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length();
        std::vector<int> ans(n+1);
        int i = 0;
        while(i<=n) {
            //printf("s[%d]=%c\n", i, s[i]);
            if(s[i] == 'D') {
                int j = i;
                while(j < n and s[j] == 'D') j++;
                int l = i;
                for(int k = j; k >= l; k--) {
                    ans[i++] = k+1;
                }
                //i=j+1;
            }
            else {
                ans[i++] = i+1;
            }
            //for(auto a: ans) printf("%d ", a); printf("\n");
        }
        return ans;
    }
    vector<int> findPermutation1(string s) {
        int n = s.length();
        std::stack<int> stack;
        std::vector<int> ans;
        for(int i = 0; i <= n; i++) {
            stack.push(i+1);
            if(s[i]=='I' or i==n) {
                while(not stack.empty()) {
                    ans.push_back(stack.top()); stack.pop();
                }
            }
        }
        
        return ans;
    }
};
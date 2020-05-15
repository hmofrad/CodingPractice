/*
 *	https://leetcode.com/problems/beautiful-arrangement-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> constructArray1(int n, int k) {
        std::vector<int> ans(n);
        int c = 0;
        for(int i = 1; i < n-k; i++) {
            ans[c++]=i;
        }
        
        for(int i = 0; i <= k; i++) {
            ans[c++]=(i%2==0) ? n-k+(i/2) : n-(i/2);
        }
        return ans;
    }
    
    vector<int> constructArray(int n, int k) {
        std::vector<int> ans; 
        for(int i = 1, j = n; i<=j;) {
            if(k>1) ans.push_back(k-- % 2 ? i++ : j--);
            else ans.push_back(i++);
        }
        return ans;
    }
};

/*

if you have n number, the maximum k can be n - 1;
if n is 9, max k is 8.
This can be done by picking numbers interleavingly from head and tail,

// start from i = 1, j = n;
// i++, j--, i++, j--, i++, j--

i: 1   2   3   4   5
j:   9   8   7   6
out: 1 9 2 8 3 7 4 6 5
dif:  8 7 6 5 4 3 2 1
Above is a case where k is exactly n - 1
When k is less than that, simply lay out the rest (i, j) in incremental
order(all diff is 1). Say if k is 5:

     i++ j-- i++ j--  i++ i++ i++ ...
out: 1   9   2   8    3   4   5   6   7
dif:   8   7   6   5    1   1   1   1 
*/


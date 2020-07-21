/*
 * https://leetcode.com/problems/pascals-triangle-ii/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> curr;
        std::vector<int> prev={1};
        for(int i = 1; i <= rowIndex; i++) {
            curr.assign(i+1,1);
            for(int j = 1; j < i; j++) {
                curr[j]=prev[j-1]+prev[j];
            }
            prev=std::move(curr);
        }
        return prev;
    }
    vector<int> getRow1(int rowIndex) {
        std::vector<int> ans(rowIndex+1, 1);
        for(int i = 1; i < rowIndex; i++) {
            for(int j = i; j>0; j--) {
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }
    vector<int> getRow0(int rowIndex) {
        std::vector<std::vector<int>> ans;
        for(int i = 0; i <= rowIndex; i++) {
            ans.push_back({});
            ans.back().resize(i+1, 1);
            for(int j = 1; j < i; j++) {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans.back();
    }
};
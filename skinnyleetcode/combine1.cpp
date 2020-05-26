/*
 *	https://leetcode.com/problems/combinations/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<vector<int>> combinations;
    void backtrack(std::vector<int> temp, int index, int n, int k) {
        if(temp.size() == k) combinations.push_back(temp);
        
        for(int i = index; i <= n; i++) {
            temp.push_back(i);
            backtrack(temp, i+1, n, k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        backtrack(std::vector<int>(), 1, n, k);
        return combinations;    
    }
};
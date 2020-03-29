/*
 *  https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int temp;
        std::vector<std::vector<int>> out;
        for (int i = 1; customfunction.f(i, 1) <= z; i++) {
            for (int j = 1; customfunction.f(i, j) <= z; j++) {
                if (customfunction.f(i, j) == z) {
                    out.push_back({i, j});
                }
            }
        }
        return out;
    }
};
/*
 *  https://leetcode.com/problems/number-of-days-in-a-month/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int numberOfDays(int Y, int M) {
        std::vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return M==2 and (Y%4==0 and Y%100 or Y%400==0) ? 29 : days[M];
        
    }
};
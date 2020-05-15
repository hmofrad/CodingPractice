/*
 *	https://leetcode.com/problems/excel-sheet-column-number/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int num = 0;
        int j = 0;
        for(int i=len-1; i>=0; i--) {
            int n = s[i]-'A'+1;
            int m = pow(26,j);
            num+=n*m;
            j++;
        }
        return num;
    }
};
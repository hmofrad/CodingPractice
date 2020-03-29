/*
 *  https://leetcode.com/problems/reverse-words-in-a-string-iii/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    //void sswap(std::string s, int left, int right) {}
    string reverseWords(string s) {
        int m = s.length();
        int j = 0;
        for(int i = 0; i < m; i++) {
           // printf("s[%d]=%c, %d\n", i, s[i], j);
            if(s[i] == ' ' or i+1 == m) {
                int len = (i+1 == m) ? i-j+1 : i-j;
                std::reverse(s.begin()+j, s.begin()+j+len);
                while(i < m and s[i] == ' ') i++;
                j = i;
            }
        }
        return(s);
    }
};
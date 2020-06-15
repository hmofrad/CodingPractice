/*
 * https://leetcode.com/problems/read-n-characters-given-read4/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int m = 0;
        int a = 0;
        while(n>0) {
            int m = min(read4(buf), n);
            a += m;
            buf += m;
            if(m<4) break;
            n-=4;
        }
        return a;
    }
};
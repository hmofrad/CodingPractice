/*
 * https://leetcode.com/problems/read-n-characters-given-read4/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
        while(true) {
            int s = read4(buf);
            s += (m+s)<=n ? 0 : -(m+s-n);
            buf += s;
            m += s;
            if(m==n or s<4) { break; }
        }
        return m;
    }
};

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution0 {
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
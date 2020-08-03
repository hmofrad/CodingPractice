/*
 * https://leetcode.com/problems/divide-two-integers/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) { return INT_MAX; }
        
        int negatives = 2;
        if(dividend > 0) { negatives--; dividend = -dividend; }
        if(divisor > 0) { negatives--; divisor = -divisor; }
        
        int quotient = 0;
        while(divisor>=dividend) {
            int p = -1;
            int v = divisor;
            while(v >= INT_MIN/2 and v + v >= dividend) {
                v += v;
                p += p;
            }
            quotient += p;
            dividend -= v;
        }
        return (negatives != 1) ? -quotient : quotient;
    }
    
    int divide0(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) { return INT_MAX; }
        
        int negatives = 2;
        if(dividend > 0) { negatives--; dividend = -dividend; }
        if(divisor > 0) { negatives--; divisor = -divisor; }
        
        int quotient = 0;
        while(dividend - divisor <= 0) {
            dividend -= divisor;
            quotient--;
        }
        
        return (negatives != 1) ? -quotient : quotient;
    }
};
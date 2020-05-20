/*
 *	https://leetcode.com/problems/mirror-reflection/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g; p %= 2;
        q /= g; q %= 2;
        return (p==1 and q==1) ? 1 : (p==1) ? 0 : 2;
    }
    
    int gcd(int a, int b) {
        return a==0 ? b : gcd(b%a, a);
    }
    
};

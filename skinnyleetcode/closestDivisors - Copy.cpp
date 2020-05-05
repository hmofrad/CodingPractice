/*
 *	https://leetcode.com/problems/closest-divisors/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    void factorize(int n, int& a, int& b) {
        int d = sqrt(n);
        while(n%d != 0) d--;
        a=d, b=n/d;
    }
    void factorize1(int n, int& a, int& b) {
        a = b = sqrt(n);
        while(a*b != n) {
            b++;
            a=n/b;
        }
    }
    vector<int> closestDivisors(int num) {
        int num1 = num+1;
        int a1 = 0, b1 = 0;
        factorize(num1, a1, b1);
        int num2 = num+2;
        int a2 = 0, b2 = 0;
        factorize(num2, a2, b2);
        
        
        return abs(a1-b1) < abs(a2-b2) ? std::vector<int>({a1, b1}) : std::vector<int>({a2, b2});
    }
};
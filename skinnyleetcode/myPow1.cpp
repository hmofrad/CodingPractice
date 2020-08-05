/*
 * https://leetcode.com/problems/powx-n/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N == 0) { return 1; }
        if(N<0) { N = -N; x = 1/x; }
        return (n%2==0) ? pow(x*x, N/2) : x*pow(x*x, N/2);
    }
    // x^n
    double myPow0(double x, int n) {
        long long N = n;
        if(N<0) { x=1/x; N=-N; }
        double ans=1;
        for(long long i = 0; i < N; i++) { ans *= x; }            
        
        return ans;
    }
};
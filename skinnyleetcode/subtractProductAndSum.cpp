/*
 *  Problem: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int subtractProductAndSum(int n) {
        if(n == 0) return(0);
        
        int prod = 1;
        int sum = 0;
        while(n) {
            int r = n%10;
            n /= 10;
            prod *= r;
            sum += r;
        }
        return(prod-sum);
    }
};
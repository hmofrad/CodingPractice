/*
 *  https://leetcode.com/problems/reverse-integer/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int reverse(int32_t x) {
        printf("%d %d\n", INT_MAX, INT_MIN);
        int y = 0;
        while(x) {
            int r = x%10;
            x/=10;
            
            if(y>INT_MAX/10 or (y==INT_MAX/10 and r>7)) return 0;
            if(y<INT_MIN/10 or (y==INT_MIN/10 and r<-8)) return 0;
            
            y = (y*10)+r;
        }
        return y;
    }
    int reverse1(int32_t x, bool sign = false) {
        if(x<0) return reverse1(-x, true);
        x=1534236469;
        int n = 0;
        int x0 = x;
        while(x0) {
            x0/=10;
            n++;
        }
        n--;
        int y=0;
        while(x) {
            int r = (x%10);
            int d = pow(10, n); n--;
            //if(r*d>INT_MAX or r*d<INT_MIN) return 0;
            y+=r*d; //overflow
            x/=10;
        }
        return sign ? -y:y;
    }
};
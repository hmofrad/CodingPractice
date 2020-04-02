/*
 *  https://leetcode.com/problems/fibonacci-number/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    
    int fib(int N) {
        if(N<=1) return(N);
        //std::vector<int> F;
        std::vector<int> F(N+1);    
        F[0] = 0;
        F[1] = 1;
        for(int n = 2; n <= N; n++) {
            F[n] = F[n-1] + F[n-2];
        }
        return(F[N]);
    }
};
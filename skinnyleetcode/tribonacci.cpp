/*
 *  https://leetcode.com/problems/n-th-tribonacci-number/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int tribonacci(int n) {
        std::vector<int> trifib(n+1);
       if(n==0) return 0; 
        if(n==1 or n==2) return 1;
        trifib[0]=0;
        trifib[1]=1;
        trifib[2]=1;
        for(int i = 3; i <= n; i++)
            trifib[i]=trifib[i-1]+trifib[i-2]+trifib[i-3]; 
        return trifib[n];
        //return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
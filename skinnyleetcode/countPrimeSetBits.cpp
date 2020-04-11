/*
 *  https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int countBits(int n) {
        int c = 0;
        while(n) {
            n &= n-1;
            c++;
        }
        return(c);
    }
    
    int isPrime(int n) {
        if(n <= 1) return false;
        
        for(int i = 2; i < n; i++) {
            if(n%i == 0) return false; 
        }
        
        return true;
    }
    
    int countPrimeSetBits1(int L, int R) {
        int count = 0;
        for(int i = L; i <= R; i++) {
            if(isPrime(countBits(i))) count++;
        }
        return(count);
    }
    
    
    int countPrimeSetBits(int L, int R) {
        //2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
        std::vector<int> map={0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
        int count = 0;
        for(int i = L; i <= R; i++) {
            if(map[countBits(i)]) count++;
        }
        return(count);
        
    }
        
    
};
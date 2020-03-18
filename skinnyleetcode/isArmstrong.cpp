/*
 *  Problem: https://leetcode.com/problems/armstrong-number/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    bool isArmstrong(int N) {
        int M = N;
        int k = 0;
        std::vector<int> digits;
        while(M) {
            int r = M % 10;
            digits.push_back(r);
            M /= 10;
            k++;
        }
        
        
        int s = 0;
        for(auto d: digits) {
            s += (int)pow(d,k);
            if(s>N) return(false);
        }
        
        return(s == N);
    }
};
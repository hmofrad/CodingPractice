/*
 *  https://leetcode.com/problems/self-dividing-numbers/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    
    bool toDigits(int num) {
        if(not num) return false;
        int num1 = num;
        std::vector<int> digits;
        while(num) {
            int r = num%10;
            if((not r) or  (num1%r)) 
                return false;
            num /= 10;
        }

        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> out;
        for(int i = left; i <= right; i++) {
            if(toDigits(i)) out.push_back(i);
        }
        return(out);
    }
};
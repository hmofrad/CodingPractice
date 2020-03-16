/*
 *  Problem:https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    int numberOfSteps (int num) {
        int n = 0;
        while(num) {
            if(num%2) {
                num--;
            }
            else{
                num /=2;
            }
            n++;
        }
        return(n);
    }
};
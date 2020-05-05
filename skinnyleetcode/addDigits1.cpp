/*
 *	https://leetcode.com/problems/add-digits/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int add(int num) {
        if(num==0) return 0; 
        int r = num%10;
        num /= 10;
        return r + add(num);
    }
    int addDigits(int num) {
        do {num=add(num);} while(num>9);
        return num;
    }
    int addDigits1(int num) {
        int ret = 0;
        while(true) {
            do{
                ret += num%10;
                num = num/10;
            } while(num);
            if(ret < 10) {
                break;
            }
            else {
                num = ret;
                ret = 0;
            }
        }
        return(ret);    
    }
};
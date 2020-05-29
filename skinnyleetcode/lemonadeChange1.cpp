/*
 *	https://leetcode.com/problems/lemonade-change/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i = 0; i < bills.size(); i++) {
            int b = bills[i];
            switch(b) {
                case 5: five++; break;
                case 10: if(five) {five--; ten++; break;} else {return false;}
                case 20: if(five and ten) {five--; ten--; twenty++; break;} else if(five>=3) {five-=3; twenty++; break;} else {return false;} 
            }
        }
        return true;
    }
};
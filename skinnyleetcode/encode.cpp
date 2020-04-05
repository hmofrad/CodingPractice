/*
 *  https://leetcode.com/problems/encode-number/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
string encode(int num) {
    num++;
    int i = 31;
    for(; i >= 0; i--) {
        
        int mask = 1 << i;
        int b = (num & mask) != 0;
        if(b) {
            num &= ~mask;  
            break;
        }
    }
    i--;
    std::string s;
    for(; i>= 0; i--) {
        int mask = 1 << i;
        int b = (num & mask) != 0;
        //printf("%d ", b);
        s.push_back('0'+b);
    }
    
    return(s);
    
        //auto s = std::bitset< 64 >( num + 1 ).to_string();
        //return s.substr(s.find('1') + 1);
    }
};
/*
0: 000 -> ""
1: 001 -> "0"
2: 010 -> "1"
3: 011 -> "00"
4: 100 -> "01"
5: 101 -> "10"
6: 110 -> "11"
7: 111  -> "000"
*/


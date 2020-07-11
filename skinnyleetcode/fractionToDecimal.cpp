/*
 * https://leetcode.com/problems/fraction-to-recurring-decimal/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //numerator=-50; denominator=8;
        if(numerator == 0) { return "0"; }
        std::string fraction;
        if((numerator<0) ^ (denominator<0)) { fraction.push_back('-'); }
        long dividend = (long) abs(numerator);
        long divisor = (long) abs(denominator);
        fraction += to_string(dividend/divisor);
        long remainder = dividend % divisor;
        if(remainder == 0) { return fraction; }
        //printf("%s %d %d\n", fraction.c_str(), remainder, fraction.length());
        fraction.push_back('.');
        std::unordered_map<long, int> map;
        while(remainder) {
            //printf("%d %d %d\n", remainder, remainder*10, (remainder*10)%10);
            if(map.count(remainder)) {
                int index = map[remainder];
                fraction.insert(index, "(");
                fraction.push_back(')');
                break;
            }
            map[remainder]=fraction.length();
            remainder *= 10;
            fraction += to_string(remainder/divisor);
            remainder %= divisor;
        }
        
        //printf("%s\n", fraction.c_str());
        
        return fraction;
    }
};
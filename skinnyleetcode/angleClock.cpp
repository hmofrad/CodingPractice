/*
 *  https://leetcode.com/problems/angle-between-hands-of-a-clock/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double clock = 360;
        double hour_part = clock/12;
        double min_part = hour_part/5;
        
        double hour1 = hour%12 * hour_part + (double) minutes/60 * hour_part;
        double min1 = minutes%60 * min_part; 
        //int min1 = (minutes%60+minutes/60) * min_part;
        //printf("%f %f\n", hour1, min1);
        double diff1 = abs(hour1-min1);
        //double diff2 = abs(abs(hour1-min1)-360);
        return min(diff1, 360-diff1);
    }
};
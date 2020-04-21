/*
 *  https://leetcode.com/problems/bulb-switcher-iii/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        uint32_t n = light.size();
        int count = 0;
        int max = -1;
        for(int i = 0; i < n; i++) {
            if(light[i]>max) max = light[i];
            if(max-i==1) count++;
        }
        return count;
    }
    int numTimesAllBlue1(vector<int>& light) {
        uint32_t n = light.size();
        uint32_t s = 0;
        int c = 0;
        for(uint32_t i = 0; i < n; i++) {
            s+=light[i];
            uint32_t s1 = ((i+1)*(i+2))/2;
            //printf("l[%d]=%d sum=%d s1=%d\n", i, light[i], s, s1);
            if(s == s1) c++;
        }
        return c;
    }
};
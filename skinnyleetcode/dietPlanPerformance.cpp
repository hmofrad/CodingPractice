/*
 *	https://leetcode.com/problems/diet-plan-performance/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points = 0;
        int size = calories.size();
        int j = 0;
        int s = 0;
        int d = 0;
        for(int i = 0; i < size; i++) {
            s +=calories[i];
            d++;
            if(d%k==0) {
                points -= (s<lower) ? 1 : 0;
                points += (s>upper) ? 1 : 0;
                s-=calories[j++];
                d--;
            }

        }
        return points;
    }
    int dietPlanPerformance1(vector<int>& calories, int k, int lower, int upper) {
        int points = 0;
        int size = calories.size();
        for(int i = 0; i <= size-k; i++) {
            int s = 0;
            for(int j = i; j < i+k; j++) {
                s+=calories[j];
            }
            points -= (s<lower) ? 1 : 0;
            points += (s>upper) ? 1 : 0;
        }
        return points;
    }
};
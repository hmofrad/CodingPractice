/*
 *  https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n= 0;
        for(int i = 0; i < arr1.size(); i++) {
            bool tf = true;
            for(int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i]-arr2[j]) <= d) {
                    tf = false;
                    break;
                }
            }
            if(tf) {
                n++;
            }
        }
        return(n);
    }
};
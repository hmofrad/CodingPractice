/*
 *	https://leetcode.com/problems/array-transformation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        if(arr.size()<=2) return arr;
        bool fixed = true;
        do{
            fixed = true;
            int first = arr[0];
            int second = arr[1];
            int third = arr[2];
            for(int i = 1; i < arr.size()-1; i++) {
                //printf("%d %d %d\n", first, second, third);
                if(first>second and second<third) {
                    arr[i]++;
                    fixed = false;
                }
                else if(first<second and second>third) {
                    arr[i]--;
                    fixed = false;
                }
                first=second;
                second=third;
                third= (i+2<arr.size()) ? arr[i+2] : third;
            }
            
            //break;
        } while(not fixed);
        
        return arr;
    }
};
/*
 *  Problem: https://leetcode.com/problems/intersection-of-three-sorted-arrays/submissions/ 
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        std::vector<int> out;
        int s1 = arr1.size();
        int s2 = arr2.size();
        int s3 = arr3.size();
        int i1 = 0;
        int i2 = 0;
        int i3 = 0;
        while(i1<s1 and i2<s2 and i3<s3) {
            //printf("%d %d %d\n", i1, i2, i3);
            if(arr1[i1] == arr2[i2] and arr2[i2] == arr3[i3]) {
                out.push_back(arr1[i1]);
                i1++;
                i2++;
                i3++;
            }
            else {
                int mn = min(arr1[i1], min(arr2[i2], arr3[i3]));
                //std::vector<int> v = {};
                //std::sort(v.begin(), v.end());
                //int min = v.front();
                //printf("%d %d %d %d\n", i1, i2, i3, min);
                if(arr1[i1] == mn) i1++;
                if(arr2[i2] == mn) i2++;
                if(arr3[i3] == mn) i3++;
            }
        }
        return(out);
    }
};
/*
 * https://leetcode.com/problems/merge-sorted-array/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = nums1.size()-1;
        int i1 = m-1;
        int i2 = n-1;
        while(i1>=0 and i2>=0) {
            if(nums1[i1]>=nums2[i2]) {nums1[j--]=nums1[i1--];}
            else {nums1[j--]=nums2[i2--];}
        }
        
        while(i1>=0) { nums1[j--]=nums1[i1--]; }
        while(i2>=0) { nums1[j--]=nums2[i2--]; }
    }
    
    
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        std::vector<int> nums11(nums1.begin(), nums1.begin()+m);
        int i = 0;
        int i1 = 0;
        int i2 = 0;
        while(i1<m and i2<n) {
            if(nums11[i1]<=nums2[i2]) {
                nums1[i++]=nums11[i1++];
            }
            else {
                nums1[i++]=nums2[i2++];
            }
        }
        while(i1<m) {
            nums1[i++]=nums11[i1++];
        }
        while(i2<n) {
            nums1[i++]=nums2[i2++];
        }

    }
};
/*
 *  https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //nums1 = {2};
        //nums2 = {};
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        int mid = n/2;
        //std::priority_queue<int, std::vector<int>, std::greater <int>> queue;
        std::priority_queue<int> queue;
        //for(int n: nums1) printf("%d ", n); printf("\n");
        //for(int n: nums2) printf("%d ", n); printf("\n");
        int i1 = 0;
        int i2 = 0;
        while(i1 < n1 or i2 < n2) {
            if(i1<n1 and i2<n2 and nums1[i1]<=nums2[i2]) { queue.push(nums1[i1]); i1++; }
            else if(i1<n1 and i2<n2 and nums1[i1]>nums2[i2]) { queue.push(nums2[i2]); i2++; }
            else if (i1<n1) { queue.push(nums1[i1]); i1++; }
            else if (i2<n2) { queue.push(nums2[i2]); i2++; }
            if(queue.size()==mid+1) {
                if(n%2) {
                    return queue.top();
                }
                else {
                    int m = queue.top(); queue.pop();
                    return double (queue.top()+m)/2;
                }
            }
        }
        return 0;
    }
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        
        
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
        //for(int n: nums1) printf("%d ", n); printf("\n");
        int mid = (nums1.size()/2);
        //printf("%d %d %d\n", mid, nums1[mid], nums1[mid-1]);
        
        return nums1.size()%2 ? nums1[mid] : (double) (nums1[mid-1]+nums1[mid])/2;
    }
};
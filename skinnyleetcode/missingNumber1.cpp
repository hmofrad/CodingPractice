/*
 *	https://leetcode.com/problems/missing-number-in-arithmetic-progression/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int d = (arr[n-1]-arr[0])/n;
        while(d and left < right) {
            int mid = left + (right-left)/2;
            if(arr[mid] == arr[0]+mid*d) left = mid+1;
            else right=mid;
        }
        return arr[0]+left*d;
    }
    int missingNumber2(vector<int>& arr) {
        int n = arr.size();
        int sum = ((arr.front()+arr.back()) * (n+1))/2;
        int sum1 = std::accumulate(arr.begin(), arr.end(), 0);
        return sum-sum1;
    }
    int missingNumber1(vector<int>& arr) {
        int n = arr.size();
        if(n==2) { return arr[0]+arr[1]-arr[0]; }
        
        int num = 0;
        for(int i = 1; i < n-1; i++) {
            int left = arr[i]-arr[i-1];
            int right = arr[i+1]-arr[i];
            if(left != right) {
                if(abs(left) > abs(right)) { num = arr[i-1] + left/2; }
                else { num = arr[i] + right/2; }
            }
        }
        return num;
    }
};
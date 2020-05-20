/*
 *	https://leetcode.com/problems/maximum-of-absolute-value-expression/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
     int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
         int ans = 0;
         int size = arr1.size();
         int closest = 0;
         int current = 0;
         std::vector<int> c = {1, -1};
         for(int p: c) {
             for(int q: c) {
                 closest = p*arr1[0] + q*arr2[0] + 0;
                 for(int i = 1; i < size; i++) {
                     current = p*arr1[i]+q*arr2[i]+i;
                     ans = max(ans,current-closest);
                     closest=min(closest, current);
                 }
             }
         }
         return ans;
     }
    int maxAbsValExpr3(vector<int>& arr1, vector<int>& arr2) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
        int size = arr1.size();
        for(int i = 0; i < size; i++) {
            printf("%d[%d %d][%d %d][%d %d][%d %d]\n", i,max1, min1, max2, min2, max3, min3, max4, min4);
            // 1st scenario arr1[i] + arr2[i] + i
            max1 = max(arr1[i]+arr2[i]+i, max1);
            min1 = max(arr1[i]+arr2[i]+i, min1);
             // 2nd scenario arr1[i] + arr2[i] - i
            max2 = max(arr1[i]+arr2[i]-i, max2);
            min2 = min(arr1[i]+arr2[i]-i, min2);
            // 3rd scenario arr1[i] - arr2[i] - i
            max3 = max(arr1[i]-arr2[i]-i, max3);
            min3 = min(arr1[i]-arr2[i]-i, min3);
            // 4th scenario arr1[i] - arr2[i] + i
            max4 = max(arr1[i]-arr2[i]+i, max4);
            min4 = min(arr1[i]-arr2[i]+i, min4);
            printf("%d[%d %d][%d %d][%d %d][%d %d]\n", i,max1, min1, max2, min2, max3, min3, max4, min4);
        }
        int diff1 = max1-min1;
        int diff2 = max2-min2;
        int diff3 = max3-min3;
        int diff4 = max4-min4;
        printf("%d %d %d %d\n", diff1, diff2, diff3, diff3);
        return (max({diff1, diff2, diff3, diff4}));
    }
    int maxAbsValExpr2(vector<int>& arr1, vector<int>& arr2) {
        int size1 = arr1.size();
        std::vector<int> l1, l2, l3, l4;
        for(int i = 0; i < size1; i++) {
            l1.push_back(arr1[i]+arr2[i]+i);
            l2.push_back(arr1[i]-arr2[i]+i);
            l3.push_back(-arr1[i]+arr2[i]+i);
            l4.push_back(-arr1[i]-arr2[i]+i);
        }
        
        int ans;
        ans += std::max(l1.begin(), l1.end()) - std::min(l1.begin(), l1.end());
        ans += std::max(l2.begin(), l2.end()) - std::min(l2.begin(), l2.end());
        ans += std::max(l3.begin(), l3.end()) - std::min(l3.begin(), l3.end());
        ans += std::max(l4.begin(), l4.end()) - std::min(l4.begin(), l4.end());
        return ans;
    }
    
    int maxAbsValExpr1(vector<int>& arr1, vector<int>& arr2) {
        int size1 = arr1.size();
        int size2 = arr2.size();
        int max_v = 0;
        for(int i = 0; i < size1; i++) {
            for(int j = 0; j < size1; j++) {
                int v = abs(arr1[i]-arr1[j]) + abs(arr2[i]-arr2[j]) + abs(i-j);
                //printf("%d %d %d %d\n", i, j, v, max_v);
                if(v>max_v) max_v = v;
            }
        }
        return max_v;
    }
};
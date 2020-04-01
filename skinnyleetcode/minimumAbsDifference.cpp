/*
 *  https://leetcode.com/problems/minimum-absolute-difference/submissions/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::vector<int> arr1(arr);
        std::sort(arr1.begin(), arr1.end());
        
        int d = INT_MAX;
        int m = arr.size();
        for(int i = 0; i < m-1; i++) {
            int d1 = arr1[i+1]-arr1[i];
            d = (d1 < d) ? d1 : d;
        }
        
        std::vector<std::vector<int>> ans;
        for(int i = 0; i < m-1; i++) {
            int d1 = arr1[i+1]-arr1[i];
            if(d1 == d) ans.push_back({arr1[i], arr1[i+1]});
        }
        return(ans);
    }
    
    vector<vector<int>> minimumAbsDifference1(vector<int>& arr) {
        int m = arr.size();
        int min_absol_dist = INT_MAX;
        for(int i = 0; i < m-1; i++) {
            for(int j = i+1; j<m; j++) {
                int d=abs(arr[i]-arr[j]);
                if(d < min_absol_dist) min_absol_dist = d;
            }
        }
        std::vector<std::vector<int>> ans;
        for(int i = 0; i < m-1; i++) {
            for(int j = i+1; j<m; j++) {
                if(abs(arr[i]-arr[j]) == min_absol_dist) {
                    if(arr[i] < arr[j]) ans.push_back({arr[i],arr[j]});
                    else ans.push_back({arr[j],arr[i]});
                }
            }
        }
        
        std::sort(ans.begin(), ans.end(), [](std::vector<int> a, std::vector<int> b) {
            if(a[0]<b[0]) return(true);
            else if(a[0]==b[0]) return(a[1] < b[1]);
            else return(false);
        });
        
        return(ans);
    }
};
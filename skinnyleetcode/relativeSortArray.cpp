/*
 *  https://leetcode.com/problems/relative-sort-array/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::unordered_map<int, int> m2_map;
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int m2 = arr2.size();
        for(int i = 0; i < m2; i++) {
            m2_map[arr2[i]] = i;
        }
        
        std::sort(arr1.begin(), arr1.end(), [this](int a, int b) {
        if((m2_map.find(a) != m2_map.end()) and (m2_map.find(b) != m2_map.end())) {
                                                return(m2_map[a] < m2_map[b]);
        }
        else if (m2_map.find(a) != m2_map.end()) {
            return true;
        }
        else if(m2_map.find(b) != m2_map.end()) {
            return false;
        }
        else {
            return (a<b);
        }
        });
        return(arr1);
    }
};
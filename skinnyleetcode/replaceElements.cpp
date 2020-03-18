/*
 *  Problem: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    
    int get_max(vector<int> arr, int left, int right) {
        
        int max_v = arr[left];
        //int mx_i = left;
        for(int i = left+1; i <= right; i++) {
            if(arr[i] > max_v) {
                max_v = arr[i];
                //max_i = i;
            }
        }
        return(max_v);
    }
    
    vector<int> replaceElements1(vector<int>& arr) {
        for(int i = 0; i < arr.size()-1; i++) {
            arr[i] = get_max(arr, i+1, arr.size()-1);
        }
        arr.back() = -1;
        return(arr);
    }
    
    vector<int> replaceElements(vector<int>& arr) {
        int max = arr.back();
        arr.back() = -1;
        for(int i = arr.size()-2; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = max;
            max = (temp > max) ? temp : max;
        }
        return(arr);
    }
};
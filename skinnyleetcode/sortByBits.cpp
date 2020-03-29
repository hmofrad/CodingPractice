/*
 *  https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    /*
    int max_v(std::vector<int> arr) {
        int mx = 0;
        for(auto a: arr)
            if(a > mx) mx = a;
        }
        return(mx);
    }
    */
    int count_bits(int num) {
        int c = 0;
        while(num) {
            num &= (num-1);
            c++;
        }
        return(c);
    }
    
    void my_sort(std::vector<int>& arr, std::vector<int> weights) {
        int m = arr.size();
        int i = 0;
        int j = 0;
        for(int i = 0; i < m-1; i++) {
            int mn_v = arr[i];
            int mn_v_i = i;
            int mn_w = weights[i];
            int mn_w_i = j;
            for(int j = i+1; j < m; j++) {
                if(mn_v > arr[j]) {
                    mn_v = arr[j];
                    mn_v_i = j;
                }
                if(mn_w > weights[j]) {
                    mn_w = weights[j];
                    mn_w_i = j;
                }
            }
            if(weights[i] > mn_w) {
                std::swap(arr[i], arr[mn_w_i]);
                std::swap(weights[i], weights[mn_w_i]);
            }
            else if((weights[i] == mn_w) and (arr[i] > mn_v)) {
                    std::swap(arr[i], arr[mn_v_i]);
                    std::swap(weights[i], weights[mn_v_i]);
            }
        }
    
    }
    
    std::unordered_map<int, int> map;
    vector<int> sortByBits(vector<int>& arr) {
        int m = arr.size();
        //int mx = max_v(arr);
        std::vector<int> bits(m);
        
        for(int i = 0; i < m; i++) {
            //bits[i] = count_bits(arr[i]);
            if(map.find(arr[i]) == map.end()) {
                map[arr[i]]=count_bits(arr[i]);
            }
        }
        
        ///my_sort(arr, bits);

        
        std::sort(arr.begin(), arr.end(), [this](int a, int b) {
            if(map[a] < map[b]) return true;
            else if (map[a] > map[b]) return false;
            else return (a < b);
        });
        
        return(arr);
        
    }
};
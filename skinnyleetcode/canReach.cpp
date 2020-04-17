/*
 *  https://leetcode.com/problems/jump-game-iii/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    bool canReach2(vector<int>& arr, int start) {
        int size = arr.size();
        std::vector<bool> dp(size+1);
        
        
        
        for(int i = 1; i < size; i++) {
            if((i+arr[i] < size and i+arr[i] >= 0 and arr[i+arr[i]] == 0) or
               (i-arr[i] < size and i-arr[i] >= 0 and arr[i-arr[i]] == 0)) dp[i] = true;
        }
        return false;
    }    
    
    bool canReach1(vector<int>& arr, std::vector<bool>& visited, int i) {
       // printf("%d %d %d\n", i, i+arr[i], i-arr[i]);
        if(visited[i]) return false;
        visited[i] = true; 
        
        int size = arr.size();
        int index = i + arr[i];
        int index1 = i - arr[i];
        
        if((index < 0 or index >= size) and (index1 < 0 or index1 >= size)) return false;
        if((index >= 0 and index < size and arr[index] == 0) or (index1 >= 0 and index1 < size and arr[index1] == 0)) return true;
        
        bool tf = false;
        if(index >= 0 and index < size) tf = canReach1(arr, visited, index);
        bool tf1 = false;
        if(index1 >= 0 and index1 < size) tf1 = canReach1(arr, visited, index1);
        
        return tf or tf1;
        
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        /*
        for(int i = 0; i < arr.size(); i++) {
            printf("%2d ", i);
        }
        printf("\n");
        for(int i = 0; i < arr.size(); i++) {
            printf("%2d ", arr[i]);
        }
        printf("\n");
        for(int i = 0; i < arr.size(); i++) {
            printf("%2d ", i+arr[i]);
        }
        printf("\n");
                for(int i = 0; i < arr.size(); i++) {
            printf("%2d ", i-arr[i]);
        }
        printf("\n");
        */
        int size = arr.size();
        std::vector<bool> visited(size);
        
        return canReach1(arr, visited, start);

    }
};

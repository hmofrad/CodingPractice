/*
 *  https://leetcode.com/problems/daily-temperatures/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size();
        std::vector<int> stack;
        std::vector<int> ans(size);
        for(int i = 0; i < size; i++) {
            while(not stack.empty() and T[i] > T[stack.back()]) {int index = stack.back(); stack.pop_back(); ans[index] = i-index;}
            stack.push_back(i);
        }
        return ans;
    }
    
    
    vector<int> dailyTemperatures2(vector<int>& T) {
        int size = T.size();
        std::vector<int> S(size);
        S[size-1] = T[size-1];
        for(int i = size-2; i >= 0; i--) {
            S[i] = max(S[i+1], T[i]);
        }
        
        for(int t: T) printf("%d ", t); printf("\n");
        for(int s: S) printf("%d ", s); printf("\n");
        
        
        int i = 0;
        while(i < size) {
            int j = i+1;
            
            if(j < size and S[j] > T[i]) {
                while(j < size and  T[j] <= T[i]) j++;
                T[i] = (j<size and T[j] > T[i]) ? j-i : 0;
            }
            else {
                T[i] = 0;
            }
            
            
            
            i++;
        }
        
        
        return(T);
        
    }
    
    
    vector<int> dailyTemperatures1(vector<int>& T) {
        int size = T.size();
        int i = 0;
        while(i < size) {
            int j = i+1;

            while(j < size and T[j] <= T[i] ) j++;
            
            T[i] = (j<size and T[j] > T[i]) ? j-i : 0;
            
            i++;
        }
        return(T);
    }
    
};
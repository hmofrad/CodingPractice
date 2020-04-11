/*
 *  https://leetcode.com/problems/range-addition/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        //int size = updates.size();
        std::vector<int> ans(length);
        
        for(std::vector update: updates) {
            int startIndex = update[0];
            int endIndex = update[1];
            int inc = update[2];
            
            ans[startIndex] += inc;
            //ans[min(endIndex+1, length)] -= inc;
            if(endIndex < length-1) ans[endIndex+1] -= inc;
            //else if(endIndex == size-1) ans[endIndex] -= inc;
            printf("%d %d %d\n", startIndex, endIndex, inc);
            for(int a: ans) printf("%d ", a); printf("\n");
        }
        
       // for(int a: ans) printf("%d ", a); printf(" %d\n", length);
        /*
        int sum = ans[0];
        for(int i = 1;i < length; i++) {
            //int temp = ans[i];
             //ans[i] += sum;
            //sum += temp;
            //printf("%d %d %d --> %d\n", i, ans[i-1], ans[i], ans[i] + ans[i-1]);
            ans[i] += ans[i-1];
            //sum = ans[i];
            
        }
        */
        partial_sum(ans.begin(), ans.end(), ans.begin());
        /*
        for(int a: ans) printf("%d ", a); printf("\n");
        
        partial_sum(ans.begin(), ans.end(), ans.begin());
        
        for(int a: ans) printf("%d ", a); printf("\n");
        */
        //ans.pop_back();
        return(ans);
    }
    
    vector<int> getModifiedArray2(int length, vector<vector<int>>& updates) {
        std::sort(updates.begin(), updates.end(), [](std::vector<int> a, std::vector<int> b) {
            return(a[0] < b[0]);});
        
        std::vector<int> ans(length);
        
        int size = updates.size();
        
        
        int i = 0;
        while(i <= size-2) {
            int a1 = updates[i][0];
            int a2 = updates[i][1];
            int a3 = updates[i][2];
            
            int b1 = updates[i+1][0];
            int b2 = updates[i+1][1];
            int b3 = updates[i+1][2];
            
            //int m1 = min(a1, b1);
           // int m2 = max(a2, b2);
            
            int i1 = min(a2, b1);
            int i2 = max(a2, b1);
            
            for(int j = a1; j<i1; j++) {
                ans[j] += a3;
            }
            
            for(int j = b1; j<i1; j++) {
                ans[j] += b3;
            }
            
            for(int j = i1; j <= i2; j++) {
                ans[j] += (a3 + b3);
            }
            
            for(int j = i2+1; j <= a2; j++) {
                ans[j] += a3;
            }
            
            for(int j = i2+1; j <= b2; j++) {
                ans[j] += b3;
            }
            
            i+=2;
        }
        
        if(i<size){
            int startIndex = updates[i][0];
            int endIndex = updates[i][1];
            int inc = updates[i][2];
            for(int i = startIndex; i <= endIndex; i++) {
                ans[i]+=inc;
            }
        }
        
        return(ans);
        
    }
    vector<int> getModifiedArray1(int length, vector<vector<int>>& updates) {
        std::vector<int> ans(length);
        for(std::vector<int> update: updates) {
            int startIndex = update[0];
            int endIndex = update[1];
            int inc = update[2];
            for(int i = startIndex; i <= endIndex; i++) {
                ans[i] += inc;
            }
        }
        return(ans);
    }
};
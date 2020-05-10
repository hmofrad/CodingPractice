/*
 *	https://leetcode.com/problems/grumpy-bookstore-owner/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int dfs(vector<int>& customers, vector<int>& grumpy, int index, int len, int value1, int value2) {
        int size = customers.size();
        if(index>=size) return max(value1, value2);
        //printf("%d %d %d %d\n", index, len, value1, value2);
        int gain1 = 0;
        int gain2 = 0;
        if(len) {
            for(int i = index; i < min(index+len, size); i++) {
                gain1 += customers[i];
            }
        }
        gain2 = grumpy[index]==0 ? customers[index] : 0;
        
        return max(dfs(customers, grumpy, len ? index+len : index+1 , 0, value1+gain1, value2+gain2), dfs(customers, grumpy, index+1, len, value1+gain2, value2+gain2));
    }
    int maxSatisfied1(vector<int>& customers, vector<int>& grumpy, int X) {
        return dfs(customers, grumpy, 0, X, 0, 0);
    }
    
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int size = customers.size();
        int satisfied = 0;
        for(int i = 0; i < size; i++) 
            if(grumpy[i]==0 and customers[i]) { satisfied += customers[i]; customers[i]=0; grumpy[i]=1;}
        
        int happiest = 0;
        int happy = 0;
        int j = 0;
        for(int i = 0; i < size; i++) {
            happy +=customers[i];
            if(grumpy[i]) {
                X--;
                if(X<0) {
                    if(grumpy[j]) {
                        happy -=customers[j];
                        j++;
                    }
                    X++;
                }
            }
            happiest = max(happy, happiest);
        }
        
        
        return satisfied+happiest;
    }
    
    
};


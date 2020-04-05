/*
 *  https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;
        while(arr.size() > 1) {
            int currentProduct = INT_MAX;
            int removeIndex = -1; 
            for(int i = 1; i < arr.size(); i++) {
                int firstNum = arr[i-1];
                int secondNum = arr[i];
                int product = firstNum * secondNum;
                if(currentProduct > product) {
                    currentProduct = product;
                    if(firstNum < secondNum) removeIndex = i-1;
                    else removeIndex = i;
                }
            }
            
            result += currentProduct;
            if(removeIndex >= 0) arr.erase(arr.begin()+removeIndex);
        }
        return result;
    }
};
/*
 *  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int size = prices.size();
        int profit = 0;
        if(prices.size()>1) {
            int buy = prices[0];
            for(int i = 1; i < size; i++) {
                int p = prices[i];
                if(p < buy) {
                    buy = p;
                }
                else if (p-buy>profit) profit = p-buy;
            }
        }
        return profit; 
    }
    int maxProfit1(vector<int>& prices) {
        int size = prices.size();
        int profit = 0;
        for(int i = 0; i < size-1; i++) {
            for(int j = i+1; j < size; j++) {
                int diff = prices[j]-prices[i];
                if(diff > profit) {
                    profit = diff;
                }
            }
        }
        return profit;
    }
};
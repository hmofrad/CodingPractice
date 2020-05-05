/*
 *	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max_profit = 0;
        for(int i = 1; i < size; i++) {
            max_profit += (prices[i]>prices[i-1]) ? prices[i]-prices[i-1] : 0;
        }
        return max_profit;
    }
    int maxProfit2(vector<int>& prices) {
        int valley = prices[0];
        int peak = prices[0];
        int max_profit = 0;
        
        int size = prices.size();
        int i = 0;
        while(i < size-1) {
            while(i<size-1 and prices[i]>=prices[i+1]) i++;
            valley=prices[i];
            while(i<size-1 and prices[i]<=prices[i+1]) i++;
            peak = prices[i];
            max_profit += peak-valley;
        }
        return max_profit;
    }
    
    
    int calc(vector<int>& prices, int index) {
        int size = prices.size();
        if(index>=size)  return 0;
        int max = 0;
        for(int i = index; i < size; i++) {
            int max_profit = 0;
            for(int j = i+1; j < size; j++) {
                if(prices[j] > prices[i]) {
                    int profit = calc(prices, j+1) + prices[j]-prices[i];
                    if(profit > max_profit) max_profit = profit;
                }
            }
            if(max_profit>max) max = max_profit;
        }
        return max;
    }
    int maxProfit1(vector<int>& prices) {
        return calc(prices, 0);
    }
};
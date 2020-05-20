/*
 *	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        if(size<2) return 0;
        std::vector<int> hold(size);
        std::vector<int> sold(size);
        hold[0]-=prices[0];
        for(int i = 1; i < size; i++) {
            hold[i] = max(hold[i-1], sold[i-1]-prices[i]);
            sold[i] = max(sold[i-1], hold[i-1]-fee+prices[i]);
        }
        return sold[size-1];
    }
    int maxProfit2(vector<int>& prices, int fee) {
        int size = prices.size();
        int cash = 0;
        int hold = -prices[0];
        for(int i = 1; i < size; i++) {
            cash = max(cash, hold+prices[i]-fee);
            hold = max(hold, cash-prices[i]);
        }
        return cash;
    }
    
    int maxProfit1(vector<int>& prices, int fee) {
        int size = prices.size();
        int buy = 0;
        int max_profit = 0;
        for(int i = 0; i < size; i++) {
            if(buy == 0) {buy=prices[i]; continue;}
            int this_profit = prices[i]-buy-fee;
            if(this_profit > max_profit) {
                max_profit += this_profit;
                buy = 0;
            }
        }
        return max_profit;
    }
};
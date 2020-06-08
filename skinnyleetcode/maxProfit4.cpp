/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int prev_sell = 0;
        int prev_buy = 0;
        
        for(int price: prices) {
            prev_buy = buy;
            buy = max(prev_sell-price, buy);
            prev_sell = sell;
            sell = max(prev_buy+price, sell);
        }
        return sell;
    }
    
    
    int maxProfit2(vector<int>& prices) {
        int size = prices.size();
        if(size<2) return 0;
        std::vector<int> s0(size);
        std::vector<int> s1(size);
        std::vector<int> s2(size);
        s0[0]=0;
        s1[0]=-prices[0];
        s2[0]=INT_MIN;
        for(int i = 1; i < size; i++) {
            s0[i]=max(s0[i-1],s2[i-1]);
            s1[i]=max(s1[i-1],s0[i-1]-prices[i]);
            s2[i]=s1[i-1]+prices[i];
        }
        return max(s0[prices.size()-1], s2[prices.size()-1]);
        
    }
    int maxProfit1(vector<int>& prices) {
        int sold = INT_MIN;
        int held = INT_MIN;
        int reset = 0;
        for(int price: prices) {
            int pre_sold = sold;
            sold = held + price;
            held = max(held, reset-price);
            reset = max(reset, pre_sold);
        }
        return max(sold, reset); 
    }
};
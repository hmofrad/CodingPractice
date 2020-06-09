/*
 * https://leetcode.com/problems/coin-change/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        std::vector<int> dp(amount+1, max);
        dp[0]=0;
        for(int i = 1; i <= amount; i++) {
            for(int coin: coins) {
                dp[i]= (coin<=i) ? min(dp[i], dp[i-coin]+1) : dp[i];
            }
        }
        return dp[amount]>amount ? -1 : dp[amount];
        
    }
    int backtrack(std::vector<int>& coins, int amount, std::vector<int>& mem) {
        if(amount<0) return -1;
        if(amount == 0) return 0;
        if(mem[amount]!=0) return mem[amount];
        int min = INT_MAX;
        for(int coin: coins) {
            int res = backtrack(coins, amount-coin, mem);
            if(res>=0 and res<min) min = res+1;
        }
        mem[amount]= (min == INT_MAX) ? -1 : min;
        return mem[amount];
    }
    
    int coinChange3(vector<int>& coins, int amount) {
        if(amount<1) return 0;
        std::vector<int> mem(amount+1);
        return backtrack(coins, amount, mem);
    }
    int coinChange2(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        if(coins.empty()) return -1;
        int count = 0;
        int prev_amount = amount;
        while(amount) {
            int coin = -1;
            for(int c: coins) {
                if(c<=amount) coin = c;
                else break;
            }
            if(coin==-1) return -1;
            count += amount/coin;
            amount %= coin;
            if(prev_amount==amount) return -1;
            prev_amount=amount;
        }
        return count;
    }
    
    
    int coinChange1(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
            int dividend = amount;
    int num = 0;
    int i = coins.size() - 1;
    
    int quotient = 0;
    int remainder = 0;
    while(i>=0) {
        auto divisor = coins[i];
        quotient  = dividend / divisor;
        remainder = dividend % divisor;
        num += quotient;
        //printf("%d %d %d %d %d\n", i, dividend, divisor, quotient, remainder);
        dividend = remainder;
        i--;
    }
    //printf("%d\n", dividend);
          
    
    return((dividend) ? -1 : num);   
    }
};
/*
 *  Compile & Execute: g++ -o maxProfit maxProfit.cpp -std=c++11 && ./maxProfit
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

int maxProfit(std::vector<int>& prices) {
    int profit = 0;
    int short_profit = 0;
    int buy = 0;
    int sell = 0;
    int m = prices.size();
    for(int i = 0; i < m; i++)
        printf("%d ", prices[i]);
    printf("\n");
    
    if(m > 1) {
        //int buy = prices[0];
        //int sell = prices[1];
        //profit = sell - buy;
        //int short_profit = 0;
        for(int i = 0; i < m - 1; i++) {
            for(int j = i+1; j < m; j++) {
                buy = prices[i];
                sell = prices[j];
                short_profit = sell - buy;
                //printf("i=%d j=%d buy=%d sell=%d p=%d sp=%d\n", i, j, buy, sell, profit, short_profit);
                if(short_profit > profit) {
                    printf("i=%d j=%d buy=%d sell=%d p=%d sp=%d\n", i, j, buy, sell, profit, short_profit);
                    profit = short_profit;
                }
            }
        }
    }
    
    return(profit);
}


int main(int argc, char** argv) {
std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    printf("maxProfit=%d\n", maxProfit(prices));
    return(0);
}
/*
 *  Problem: lemonadeChange
 *  Compile: g++ -o lemonadeChange lemonadeChange.cpp -std=c++11 && ./lemonadeChange
 *  Execute: ./lemonadeChange
 *  (c) Mohammad Mofrad, 2018
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

bool lemonadeChange(std::vector<int>& bills) {
    bool change = true;
    int m = bills.size();
    for(int i = 0; i < m; i++) {
        printf("%d ", bills[i]);
    }
    printf("\n");
    int n = 3; // 5, 10, 20
    std::vector<int> wallet(n);
    int lemonadePrice = 5;
    for(int i = 0; i < m; i++) {
        //printf("%d ", bills[i]);
        if(bills[i] == 5) {
            wallet[0]++;
        }
        else if(bills[i] == 10) {
            if(wallet[0] > 0) {
               wallet[0]--;
               wallet[1]++;
            }
            else {
                change = false;
                break;
            }
        }
        else {
            if(wallet[0] > 0) {
                if(wallet[1] > 0) {
                    wallet[0]--;
                    wallet[1]--;
                    wallet[2]++;
                } else {
                    if(wallet[0] >= 3) {
                        wallet[0] -= 3;
                        wallet[2]++;
                    }
                    else {
                    change = false;
                    break;
                    }
                }                    
                
            } else {
                change = false;
                break;
            }
            
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", wallet[i]);
    }
    printf("\n");
    return(change);
}
int main(int argc, char** argv) {
    std::vector<int> bills = {5, 5, 5, 10, 20};
    printf("Lemonade? %d\n", lemonadeChange(bills));
    return(0);
}
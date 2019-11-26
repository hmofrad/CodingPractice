/*
 *  Problem: https://leetcode.com/problems/linked-list-random-node/
 *  Compile: g++ -o getRandom getRandom.cpp -std=c++11 && ./getRandom #-fsanitize=address 
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
#include <unordered_set>
#include <stack>
#include <numeric>
#include <map>
#include <cmath>
#include <unordered_map>
#include <bits/stdc++.h> 
#include <random>

int getRandom() {
    int n = 4;
    int f = 1;
    
    std::vector<int> roulette_wheel(n*f);
    for(int i = 0; i < n; i++) {
        std::fill(roulette_wheel.begin()+(i*f), roulette_wheel.begin()+((i+1)*f), i);
    }
    
    for(int i = 0; i < n*f; i++) {
        printf("%d ", roulette_wheel[i]);
        if(not ((i+1)%10))
            printf("\n");
    }
    
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(roulette_wheel), std::end(roulette_wheel), rng);
    
    for(int i = 0; i < n*f; i++) {
        printf("%d ", roulette_wheel[i]);
        if(not ((i+1)%10))
            printf("\n");
    }
    
    srand(time(0));
    
    int r = rand() % ((n*f) - 1);

    printf("%d\n", r);
    return(roulette_wheel[r]);    
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:

    std::vector<int> values;
    int n = 0;
    bool set = false;
    Solution(ListNode* head) {
        while(head) {
            values.push_back(head->val);
            head = head->next;
            //n++;
        }
        n = values.size();
    }
    
    int getRandom() {
       // if(n == 1) return(values[0]);
        if(not set) {
            srand(time(0));            
            set = true;
        }

        return(values[rand() % n]);
        
    }
};
*/



int main(int argc, char **argv){
    int r = getRandom();
    printf("rand = %d\n", r);
    return(0);
}







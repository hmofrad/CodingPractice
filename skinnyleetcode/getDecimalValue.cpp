/*
 *  Problem: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/
 *  Compile: g++ -o getDecimalValue getDecimalValue.cpp -std=c++11 -g -Wall -fsanitize=address && ./getDecimalValue
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
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
    int getDecimalValue(ListNode* head) {
        
        std::vector<int> bits;
        while(head) {
            bits.push_back(head->val);
            head = head->next;
        }
        
        int n = 0;
        for(int i = 0; i < bits.size(); i++) {
            if(bits[bits.size()-1-i])
                n += pow(2,i);
        }
        
        return(n);
    }
};
*/
 
 
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <cmath>
int getDecimalValue(std::vector<int> v) {
    int n = 0;
    int i = 0;
    std::reverse(v.begin(), v.end());
    for(auto w: v) {
        if(w)
            n += pow(2,i);
        i++;
        //head = head->next;
    }
    printf("%d\n", n);
    return(n);
}

int main(int argc, char** argv){
    std::vector<int> v = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    int r = getDecimalValue(v);
    return(0);
}
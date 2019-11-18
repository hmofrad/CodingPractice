    /*
 *  Problem: https://leetcode.com/problems/odd-even-linked-list/
 *  Compile: g++ -o oddEvenList oddEvenList.cpp -std=c++11 && ./oddEvenList #-fsanitize=address 
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

struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


void traverse(ListNode* head) {
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return(head);
    
    ListNode* even = head->next;
    ListNode* odd = head;
    ListNode* evenHead = head->next;
    
    while(even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    
    return(head);
}




int main(int argc, char **argv){
    //1->2->3->4->5->NULL    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    traverse(head);
    ListNode* head1 = oddEvenList(head);
    traverse(head1);
    return(0);
}







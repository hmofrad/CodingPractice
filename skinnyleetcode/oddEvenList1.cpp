/*
 *	https://leetcode.com/problems/odd-even-linked-list/solution/
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
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even1 = even;
        
        while(even1 and even1->next) {
            odd->next=even1->next;
            odd=odd->next;
            even1->next=odd->next;
            even1=even1->next;
        }
        odd->next=even;
        return head;
    }
    ListNode* oddEvenList1(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        ListNode* odd = nullptr;
        ListNode* odd1 = nullptr;
        ListNode* even = nullptr;
        ListNode* even1 = nullptr;
        
        int c=0;
        while(head) {
            c++;
            
            
            if(c%2==0) {
                if(even==nullptr) { even = head; even1 = even; }
                else { even1->next=head; even1=even1->next; } 
            }
            else {
                if(odd==nullptr) { odd = head; odd1 = odd; }
                else { odd1->next=head; odd1=odd1->next; }
            }
            
            //printf("%d %d\n", head->val, c);
            head=head->next;
        }
        
        //printf("[%p %p] [%p %p]\n", odd, odd1, even, even1);
        if(odd1) odd1->next=even;
        if(even) even1->next = nullptr;
        
        //odd1=odd;
        //while(odd1) {printf("%d ", odd1->val); odd1=odd1->next;} printf("\n");
        //even1=even;
        //while(even1) {printf("%d ", even1->val); even1=even1->next;} printf("\n");
        
        return odd;
    }
};
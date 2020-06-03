/*
 *  https://leetcode.com/problems/add-two-numbers/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0); ListNode* current = head;
        int carry = 0;
        while(l1 or l2) {
            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;
            int s = x + y + carry;
            carry = s/10;
            //printf("[%d %d %d] [%d %d %d]\n", x, y, carry, s, s/10, s%10);
            current->next = new ListNode(s%10);
            current = current->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry) current->next = new ListNode(carry);
        return head->next;
    }
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* l = l1;
        ListNode* p = nullptr;
        int carry = 0;
        while(l1 and l2) {
            int sum = (l1->val + l2->val + carry);
            carry = sum/10;
            l1->val = sum%10;
            p=l1; l1=l1->next; l2=l2->next;
        }
        if(l1) { p = l1; }
        else if(l2) {p->next = l2; p=p->next;}
        else if(carry) {p->next = new ListNode(0); p=p->next;}
        while(p and carry) {
            int sum = p->val + carry;
            carry = sum/10;
            p->val = sum%10;
            if(p->next == nullptr and carry) p->next = new ListNode(0);
            p=p->next;
        }
        return l;
    }
};
/*
 *  https://leetcode.com/problems/plus-one-linked-list/solution/
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
class Solution {
public:
    int plus_one(ListNode* head, int v) {
        int r = 0;
        if(head) {
            if(head->next) {
                r = plus_one(head->next, v);
                int value = head->val + r;
                r = value/10;
                head->val = value%10;
            }
            else {
                int value = head->val + v;
                r = value/10;
                head->val = value%10;
            }
        }
        return r;
    }
    ListNode* plusOne(ListNode* head) {
        int r = plus_one(head, 1);
        ListNode* head1 = nullptr;
        if(r) {
            head1 = new ListNode(r);
            head1->next = head;
        }
        return r ? head1 : head;
    }
};
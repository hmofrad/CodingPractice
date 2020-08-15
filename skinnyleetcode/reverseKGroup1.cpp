/*
 * https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode* curr = begin->next;
        ListNode* next = nullptr;
        ListNode* first = curr;
        ListNode* prev = begin;
        while(curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        begin->next = prev;
        first->next = curr;
        return first;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr or head->next == nullptr or k == 1) { return head; }
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* begin = root;
        int i = 0;
        while(head) {
            i++;
            if((i%k)==0) {
                begin = reverse(begin, head->next);
                head = begin->next;
            }
            else { head = head->next; }
        }
        begin = root->next;
        delete root;
        return begin;
    }

    
    
    ListNode* reverseKGroup0(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while(curr and count < k) { curr = curr->next; count++; }
        
        if(count == k) {
            curr = reverseKGroup(curr, k);
            while(count-->0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }
        return head; 
    }
};
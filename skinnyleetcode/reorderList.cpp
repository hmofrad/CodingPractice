/*
 * https://leetcode.com/problems/reorder-list/submissions/
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
    
    ListNode* reorder(ListNode* root, ListNode* curr) {
        if(curr == nullptr) { return root; }
        root = reorder(root, curr->next);
        if(root == nullptr) { return nullptr; }
        ListNode* temp = nullptr;
        if(root == curr or root->next == curr) { curr->next = nullptr; }
        else {
            temp = root->next;
            root->next = curr;
            curr->next = temp;
        }
        return temp;
    }
    
    void reorderList(ListNode* head) {
        if(head == nullptr) { return; }
        reorder(head, head->next);
    }
    void reorderList0(ListNode* head) {
        if(head == nullptr) { return; }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast=fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* temp = nullptr;
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode* first = head;
        ListNode* second = prev;
        while(second->next) {
            temp = first->next;
            first->next = second;
            first = temp;
            
            temp = second->next;
            second->next = first;
            second = temp;
        }
        
    }
};
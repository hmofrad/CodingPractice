/*
 * https://leetcode.com/problems/reverse-linked-list-ii/solution/
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
    //ListNode* head0 = nullptr;
    //ListNode* head1 = nullptr;
    //ListNode* curr = nullptr;
    
    
    
    void reverse(ListNode* head, ListNode*& head0, ListNode*& head1, ListNode*& head2, ListNode*& curr, int i, int m, int n) {
        if(head) {
            if(i==m or i+1==m) {head0=head;}
            reverse(head->next, head0, head1, head2, curr, i+1, m, n);
            if(i>=m and i<=n) {
                if(head1 == nullptr) {
                    head1 = head;
                    head2 = head->next;
                    curr=head1;
                }
                else {
                    curr->next = head;
                    curr = curr->next;
                    head->next = nullptr;
                }
            }
            else if(head1) {
                head0->next  = head1;
                //printf("%p %p\n", curr, head2);
                curr->next = head2;
                return;
            }
        }
    }
    ListNode* reverseBetween0(ListNode* head, int m, int n) {
        if(m==n) { return head; }
        ListNode* head0 = nullptr;
        ListNode* head1 = nullptr;
        ListNode* head2 = nullptr;
        ListNode* curr = nullptr;
        reverse(head, head0, head1, head2, curr, 1, m, n);
        return head0;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr) { return nullptr; }
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* ptr = temp;
        for(int i = 0; i < m-1; i++) { ptr=ptr->next; }
        
        ListNode* start = ptr->next;
        ListNode* then = start->next;
        
        for(int i = 0; i < n-m; i++) {
            start->next = then->next;
            then->next = ptr->next;
            ptr->next = then;
            then = start->next; 
        }
        
        return temp->next;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
};
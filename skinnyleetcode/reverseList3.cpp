/*
 * https://leetcode.com/problems/reverse-linked-list/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head->next == nullptr) { return head; }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution23 {
public:
    void reverse(ListNode* head, ListNode*& curr) {
        if(head) {
            reverse(head->next, curr);
            curr->next = head;
            curr=curr->next;
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;
        reverse(head, curr);
        curr->next = nullptr;
        return temp->next;
    }
};

class Solution2 {
public:
    void reverse(ListNode* head, ListNode** new_head, ListNode** curr) {
        if(head) {
            reverse(head->next, new_head, curr);
            if(*new_head == nullptr) {*new_head = head; (*new_head)->next = nullptr; *curr = *new_head;}
            else {(*curr)->next = head; *curr = (*curr)->next; (*curr)->next = nullptr;}
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        ListNode* curr = nullptr;
        reverse(head, &new_head, &curr);
        return new_head;
    }   
};

class Solution1 {
public:
    
    void traverse1(ListNode* head, ListNode** head1, ListNode** curr) {
    if(head) {
        traverse1(head->next, head1, curr);
        
        if(*head1 == NULL) {
            *head1 = new ListNode(head->val);
            (*head1)->next = NULL;
            *curr = *head1;
        }
        else {
            (*curr)->next = new ListNode(head->val);
            *curr = (*curr)->next;
            (*curr)->next = NULL;
        }
        
        
       // printf("%d ", head->val);
    }
}
    
    void traverse0(ListNode* head){
        while(head) {
            printf("%d ", head->val);
            head = head->next;
        }
    }
    ListNode* head1;
    ListNode* curr;
    void traverse2(ListNode* head){//, ListNode* head1,  ListNode* curr){
        if(head) {
            traverse2(head->next);
            if(head1 == nullptr) {head1 = head; head1->next=nullptr; curr=head1;}
            else {curr->next = head; curr = curr->next; curr->next=nullptr;}
           // printf("%d ", head->val);
        }
    }
    
    
    ListNode* reverseList(ListNode* head) {
        /*
    ListNode* list = NULL;
    ListNode* curr = NULL;
    traverse1(head, &list, &curr);
    return(list);
    */    
      // traverse0(head); printf("\n");
        //ListNode* head1 = nullptr;
        //ListNode* curr = nullptr;
        traverse2(head);//printf("\n"); //, head1, curr
        //traverse0(head1); printf("\n");
        //printf("%p\n", head1);
        
        //traverse3(head);
        
        return(head1);
    
    }
};
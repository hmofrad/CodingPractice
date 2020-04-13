/*
 *  https://leetcode.com/problems/reverse-linked-list/solution/
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
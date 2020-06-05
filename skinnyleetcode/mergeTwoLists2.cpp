/*
 * https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(0);
        ListNode* prev = prehead;
        while(l1 and l2) {
            if(l1->val<=l2->val) {prev->next = l1;  l1=l1->next;}
            else  {prev->next=l2; l2=l2->next;}
            prev=prev->next;
        }
        prev->next = (l1==nullptr) ? l2 : l1;
        return prehead->next;
    }
    ListNode* mergeTwoLists5(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* prev = prehead;
        while(l1 and l2) {
            if(l1->val <= l2->val) {prev->next = l1; l1=l1->next;}
            else {prev->next=l2; l2=l2->next;}
            prev=prev->next;
        }
        prev->next = (l1==nullptr) ? l2 : l1;
        return prehead->next;
    }
        
     ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
         if(not l1 and not l2) return nullptr;
         if(not l1 and l2) return l2;
         if(l1 and not l2) return l1;
         
        ListNode* l = l1;
        ListNode* c = l;
         ListNode* p =l;
        while(c and l2) {
            printf("%d %d %d\n",  p->val, c->val, l2->val);
            if(c->val < l2->val) { p=c; c=c->next; }
            else if(c->val > l2->val) {
                ListNode* temp = c; p->next = l2; p->next->next=temp; p=p->next; 
                l2=l2->next;
            }
            else if(c->val == l2->val) {
                p=c;
                ListNode* temp = c->next; c->next = l2; c->next->next=temp; 
                l2=l2->next;
            }
        }
        
        if(l1) { c->next=l1;}
        else if(l2) {c->next=l2;}
        return l;
    }
    
    ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) { return l2; }
        else if(l2==nullptr) { return l1; }
        else if(l1->val < l2->val) { l1->next = mergeTwoLists(l1->next, l2); return l1; }
        else { l2->next = mergeTwoLists(l1, l2->next); return l2; }
    }
    
    
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* l = nullptr;
        ListNode* c = nullptr;
        int left1 = 0;
        int left2 = 0;
        while(l1 and l2) {
            //printf("%d %d\n", l1->val, l2->val);
            if(l1->val < l2->val) {
                if(not l) { l=new ListNode(l1->val); c=l; }
                else { c->next = new ListNode(l1->val); c=c->next; }
                l1=l1->next;
            }
            else if(l2->val < l1->val) {
                if(not l) { l=new ListNode(l2->val); c=l; }
                else { c->next = new ListNode(l2->val); c=c->next; }
                l2=l2->next;
            }
            else {
                if(not l) { l=new ListNode(l1->val); c=l; c->next = new ListNode(l2->val); c=c->next; }
                else { c->next = new ListNode(l1->val); c=c->next; c->next=new ListNode(l2->val); c=c->next;}
                l1=l1->next;
                l2=l2->next;
            }
        }
        
        if(l1) {if(not l) l = l1; else c->next=l1;}
        else if(l2) { if(not l) l=l2; else c->next=l2;}
        return l;
    }
};
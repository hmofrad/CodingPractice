/*
 * https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> setA;
        std::unordered_set<ListNode*> setB;
        ListNode* head0 = headA;
        ListNode* head1 = headB;
        ListNode* head = nullptr;
        while(head0 or head1) {
            if(head0) {
                setA.insert(head0);
                if(setB.count(head0)) {head=head0; break;}
                head0 = head0->next;
            }
            if(head1) {
                setB.insert(head1);
                if(setA.count(head1)) {head=head1; break;}
                head1 = head1->next;
            }
        }
        return head;
    }
        
    
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> setA;
        ListNode* head = headA;
        while(head) {setA.insert(head); head=head->next;}
        head = headB;
        
        while(head) {
            if(setA.count(head)) { break; }
            head = head->next;
        }
        
        return head;
    }
};


class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* list = NULL;
    ListNode* headA1 = headA;
    ListNode* headB1 = headB;
    ListNode*  ptrA = NULL;
    ListNode*  ptrB = NULL;
    int len = 0;
    ListNode*  ptrA1;
    ListNode*  ptrB1;
    int len1 = 0;
    bool br = false;
    while(headA1) {
        //printf("%d\n", headA1->val);
        headB1 = headB;
        while(headB1) {   
            if(headB1->val == headA1->val) {
                len1 = 1;
                //printf("\n%d %d %d\n", headB1->val, headA1->val,len1);
                
                ptrA1 = headA1;
                ptrB1 = headB1;
                ListNode* headB2 = headB1->next;
                ListNode* headA2 = headA1->next;                    
                while(headB2 and headA2) { 
                    if(headB2->val == headA2->val) { 
                        len1++;
                        //printf("%d %d %d\n", headB2->val, headA2->val,len1);                    
                        
                        headB2 = headB2->next; 
                        headA2 = headA2->next; 
                    }
                    else {
                        
                        //br = true;
                        break;
                    }
                }
                if(len1 > len) {
                    //printf("UPDATE\n");
                    len = len1;
                    ptrA = ptrA1;
                    ptrB = ptrB1;
                }
            }
            headB1 = headB1->next; 
        }

        headA1 = headA1->next;
    }
    
    //while(headA and headB) {
    //    if(headA->val == headB->val
    //}
    
    //printf("<%d\n", len);
    ListNode* cur = NULL;
    while(len > 0) {
        if(list) {
            cur->next = new struct ListNode(ptrA->val);
            cur = cur->next;
        }
        else {
            list = new struct ListNode(ptrA->val);
            list->next = NULL;
            cur = list;
        }
        ptrA = ptrA->next;
        len--;
    }
    //printf("%d>\n", len);
    
    return(list);
    }
};
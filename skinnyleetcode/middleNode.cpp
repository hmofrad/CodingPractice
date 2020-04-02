/*
 *  https://leetcode.com/problems/middle-of-the-linked-list/submissions/
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
    int getLength(ListNode* head) {
        if(not head) return 0;
        
        return(getLength(head->next) + 1);
        
    }
    ListNode* middleNode1(ListNode* head) {
        //if(not head)
        int len = getLength(head);
        int i = 0;
        int mid = len/2;
        //printf("%d %d\n", len, mid);
        while(i != mid) {head = head->next; i++;}
        return(head);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return(slow);
    }
    
};
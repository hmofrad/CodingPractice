/*
 * https://leetcode.com/problems/merge-k-sorted-lists/solution/
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
    
    struct comp{ bool operator()(ListNode* a, ListNode* b) {return a->val > b->val;} };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        std::priority_queue<ListNode*, std::vector<ListNode*>, comp> pq;
        
        for(ListNode* list: lists) { if(list) pq.push(list); }
        
        while(not pq.empty()) {
            curr->next = pq.top();  curr=curr->next;
            ListNode* next = pq.top()->next;
            pq.pop();
            if(next) pq.push(next);
        }
        
        return head->next;
    }
};
/*
 * https://leetcode.com/problems/linked-list-cycle/submissions/
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next) {
            if(fast == nullptr or slow == nullptr) { return false; }
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
              
    bool hasCycle1(ListNode *head) {
        std::unordered_map<ListNode*, int> seen;
        int pos = -1;
        for(int i = 0; head != nullptr; head=head->next, i++) {
            if(seen.count(head) != 0) {
                pos = seen[head];
                break;
            }
            seen[head]=i;
        }
        return pos==-1 ? false : true;
    }
};
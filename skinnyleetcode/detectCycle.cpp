/*
 * https://leetcode.com/problems/linked-list-cycle-ii/submissions/
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
    
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr or head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {break;}
        }

        if(fast == nullptr or fast->next == nullptr) return nullptr;
        
        fast = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
    ListNode *detectCycle1(ListNode *head) {
        std::unordered_set<ListNode*> seen;
        ListNode* start = nullptr;
        for(int i = 0; head != nullptr; head=head->next, i++) {
            if(not seen.insert(head).second) {
                start = head;
                break;
            }
        }
        return start;
    }
};
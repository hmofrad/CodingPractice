/*
 *  https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    void traverse1(ListNode* head, std::vector<int>& vec, std::stack<int>& stack) {
        if(head){
            traverse1(head->next, vec, stack);
            while(not stack.empty() and stack.top()<=head->val) stack.pop();
            vec.push_back(0);
            vec.back() = stack.empty() ? 0 : stack.top();
            stack.push(head->val);
        }
    }
    
    
    vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> vec;
        std::stack<int> stack;
        traverse1(head, vec, stack);
        std::reverse(vec.begin(), vec.end());
        return vec;
    }
    
    
    vector<int> nextLargerNodes2(ListNode* head) {
        std::vector<int> ans;
        std::stack<int> stack;
        while(head) {ans.push_back(head->val); head=head->next;}
        int size = ans.size();
        for(int i = size-1; i >= 0; i--) {
            int v = ans[i];
            while(not stack.empty() and stack.top()<=ans[i]) stack.pop();
            ans[i]=stack.empty() ? 0 : stack.top();
            stack.push(v);
        }
        return ans;
    }
    
    
    void traverse(ListNode* head, std::vector<int>& vec, std::vector<int>& seen, int& max_so_far) {
        if(head) {
            traverse(head->next, vec, seen, max_so_far);
            seen.push_back(head->val);
            max_so_far=max(head->val, max_so_far);
            
            vec.push_back(0);
            
            if(head->val != max_so_far) {            
                for(int& s: seen)
                    if(s>head->val) vec.back()=s;
            }
            
            
            /*
            seen.insert(head->val);
            auto it = seen.lower_bound(head->val+1);
            if(it != seen.end()) vec.push_back(*it);
            else vec.push_back(0);
            */
        }
    }
    vector<int> nextLargerNodes1(ListNode* head) {
        //std::map<int, int> seen;
        std::vector<int> seen;
        std::vector<int> greaters;
        int max_so_far = 0;
        traverse(head,  greaters, seen, max_so_far);
        std::reverse(greaters.begin(), greaters.end());
        return greaters;
    }
};
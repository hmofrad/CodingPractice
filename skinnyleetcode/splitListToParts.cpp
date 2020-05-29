/*
 *	https://leetcode.com/problems/split-linked-list-in-parts/solution/
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
    int getLength(ListNode* root) {
        return root ? getLength(root->next) + 1 : 0;
    }
    
    std::vector<ListNode*> list2vec(ListNode* root, int k) {
        int l = getLength(root);
        std::vector<ListNode*> parts;
        int s = l/k;
        int r = l%k;
       // printf("%d %d %d %d\n", s, r, l, k);
        //for(int i = 0; i < k; i++) {
            
        //}
        /*
        if(s+r<k) {
            while(root) { 
                ListNode* next = root->next;
                ListNode* node = root;
                node->next = nullptr;
                parts.push_back(node);
                root=next; 
            }
        }
        else {
            */
            //printf("cc\n");
            while(root) {
                int i = 0;
                int m = (r) ? s+1 : s;
                r -= (r) ? 1 : 0;
                ListNode* prev = root;
                parts.push_back(root);
                while(i<m and root) {
                    prev = root;
                    root=root->next;
                    i++;
                }
                prev->next=nullptr;
            }
        //}
        for(int i = parts.size(); i < k; i++) parts.push_back(nullptr);

        
        return parts;
        
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        //root->next->next->next=nlptr;
        //k=3;
        /*
        k=15;
        ListNode* head = root->next->next->next;
        head->next = new ListNode(5);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(7);
        head->next->next->next->next = new ListNode(8);
        head->next->next->next->next->next = new ListNode(9);
        head->next->next->next->next->next->next = new ListNode(10);
        head->next->next->next->next->next->next->next = new ListNode(11);
        */
        return list2vec(root, k);
    }
};
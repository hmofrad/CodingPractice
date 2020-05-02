/*
 *  https://leetcode.com/problems/linked-list-components/submissions/
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
    std::map<int, ListNode*> list2map(ListNode* head) {
        std::map<int, ListNode*> list;
        while(head) {
            list[head->val]=head;
            head = head->next;
        }
        return list;
    }
    
    int union_find(std::unordered_map<int, int>& u, int a) {
        return u[a]==-1 ? a : u[a];
    }
    
    void union_merge(std::unordered_map<int, int>& u, int a, int b) {
        int u_a=union_find(u, a);
        int u_b=union_find(u, b);
        if(u_a!=u_b) u[u_a]=u_b;
    }
    
    int numComponents1(ListNode* head, vector<int>& G) {
        std::map<int, ListNode*> list = list2map(head);
        
        std::unordered_map<int, int> u;
        for(int g: G) u[g]=-1;
        
        for(int v0: G) {
            int uv0 = union_find(u, v0);
            ListNode* v = list[v0]->next;
            if(v==nullptr) continue;
            int v1 = v->val;
            if(not u.count(v1)) continue;
            int uv1 = union_find(u, v1);
            union_merge(u, uv0, uv1);
        }
        
        int ncomponents=0;
        for(auto uu: u) {ncomponents += uu.second==-1 ? 1 : 0;}
        
        return ncomponents;
    }
    int numComponents(ListNode* head, vector<int>& G) {
        std::unordered_set<int> Gset;
        for(int& g: G) Gset.insert(g);
        int count = 0;
        while(head) {
            if(Gset.count(head->val) and (head->next == nullptr or not Gset.count(head->next->val))) count++;
            head=head->next;
        }
        return count; 
    }
};
/*
 *	https://leetcode.com/problems/add-two-numbers-ii/submissions/
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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1, s2;
        while(l1) {s1.push(l1->val); l1=l1->next;}
        while(l2) {s2.push(l2->val); l2=l2->next;}
        
        ListNode* head = new ListNode(0);
        //ListNode* curr = nullptr;
        int s=0;
        while(not s1.empty() or not s2. empty()) {
            if(not s1.empty()) {s+=s1.top(); s1.pop();}
            if(not s2.empty()) {s+=s2.top(); s2.pop();}
            head->val= s%10;
            ListNode* node = new ListNode(s/10);
            node->next = head;
            head = node;
            s/=10;
        }
        
        return head->val == 0 ? head->next : head;
        
    }
    
    
    
    
    int r = 0;
    ListNode* prev = nullptr;
    void add1(ListNode* l1, ListNode* l2) {
        if(l1 and l2) {
            prev=l1;
            add1(l1->next, l2->next);
            int s = l1->val+l2->val;
            r+=s;
            r%=10;
            l1->val=r/10;
        }
        else if(l2) {
            prev->next=l2;
        }
    }
    
    void add(ListNode* l1, ListNode* l2) {
        
    }
    
    std::vector<int> add(std::vector<int>& n1, std::vector<int>& n2) {
        int s1 = n1.size();
        int s2 = n2.size();
        int c = 0;
        int d=s1-s2;
        for(int i=s2-1; i >= 0; i--) {
          //  printf("[%d %d] [%d %d] %d\n", i+d, n1[i+d], i, n2[i], r);
            int s = n1[i+d] +n2[i] + c;
            if(s>=10) { c=s/10; s%=10; }
            else {c=0;}
            n1[i+d]=s;
        }
        //for(int i: n1) printf("%d ", i); printf("\n");
        
        if(c and d) {
            for(int i = d-1; i >= 0; i--) {
                int s = n1[i] + c;
                if(s>=10) { c=s/10; s%=10; }
                else {c=0;}
                n1[i]=s;
            }
        }
        //printf("ddd\n");
        if(c) {std::vector<int> t = {c}; n1.insert(n1.begin(), t.begin(), t.end()); }
        
        return n1;
    }
    
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        std::vector<int> n1; while(l1) {n1.push_back(l1->val); l1=l1->next;}
        int s1 = n1.size();
        ListNode* head2 = l2;
        std::vector<int> n2; while(l2) {n2.push_back(l2->val); l2=l2->next;}        
        int s2 = n2.size();
        std::vector<int> n = (s1>=s2) ? add(n1, n2) : add(n2, n1); 
        //for(int i: n) printf("%d ", i); printf("\n");
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        for(int i: n) {
            if(head==nullptr) {head = new ListNode(i); curr = head;}
            else {curr->next = new ListNode(i); curr=curr->next;}
        }
        
        return head;
    }
};
/*
 *	https://leetcode.com/problems/linked-list-random-node/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    ListNode* head;
    Solution(ListNode* head_) {
        head = head_;
    }
    int getRandom() {
        int ans = head->val;
        ListNode* head1 = head->next;
        for(int i = 2; head1; head1=head1->next, i++) {
            ans = (rand()%i)==0 ? head1->val : ans;            
        }
        return ans;
    }
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    //int n = 0;
    std::vector<int> values;
    int n = 0;
    bool set = false;
    Solution1(ListNode* head) {
        while(head) {
            values.push_back(head->val);
            head = head->next;
            //n++;
        }
        n = values.size();
    }
    
    /** Returns a random node's value. */
    int getRandom() {
       // if(n == 1) return(values[0]);
        if(not set) {
            srand(time(0));            
            set = true;
        }

        return(values[rand() % n]);
        
        //int r = rand() % (n - 1);
        //while(r>0){
           // head = head->next;
          //  r--;
        //}
        //return(head);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
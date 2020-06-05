/*
 * https://leetcode.com/problems/copy-list-with-random-pointer/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> map;
        Node* head1 = head;
        Node* head0 = new Node(0);
        Node* ptr = head0;
        while(head1) {
            if(map.count(head1)) {  ptr->next = map[head1];  }
            else {  ptr->next = new Node(head1->val);  map[head1]=ptr->next; }
            
            if(head1->random) {
                if(map.count(head1->random)) { ptr->next->random =  map[head1->random]; }
                else {ptr->next->random = new Node(head1->random->val); map[head1->random]=ptr->next->random;}
            }
            
            ptr=ptr->next;
            head1 = head1->next;
        }
        head1 = head;
        ptr = head0->next;
        /*
        while(head1) {
            printf("[%p %p] [%p %p]\n", head1, head1->random, ptr, ptr->random);
            head1=head1->next;
            ptr=ptr->next;
        }
        */
        
        return head0->next;
    }
    Node* copyRandomList1(Node* head) {
        //std::unordered_map<Node*, Node*> map;
        std::unordered_map<Node*, Node*> map0;
        Node* head1=head;
        Node* head0 = new Node(0);
        Node* ptr = head0;
        while(head1) {
            ptr->next = new Node(head1->val);
            map0[head1]=ptr->next;
            ptr=ptr->next;
            //map[head1]=head1->random;
            
            head1 = head1->next;
        }
        head1=head;
        ptr=head0->next;
        while(head1) {
            ptr->random = map0[head1->random];
            ptr=ptr->next;
            head1=head1->next;
        }
        
        return head0->next;    
    }
};
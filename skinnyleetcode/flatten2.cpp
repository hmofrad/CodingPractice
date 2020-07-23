/*
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    Node* flatten(Node* head) {
        Node* head0 = head;
        while(head0) {
            if(head0->child) {
                Node* next = head0->next;
                head0->next = head0->child;
                head0->next->prev = head0;
                head0->child = nullptr;
                Node* head1 = head0->next;
                while(head1->next) { head1 = head1->next; }
                head1->next = next;
                if(next) { next->prev=head1; }
            }
            head0 = head0->next;
        }
        return head; 
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution0 {
public:
    Node* flatter(Node* head, Node* next) {
    while(head->next) {
        if(head->child) {
            head->next->prev = flatter(head->child, head->next);
            head->next->prev->next = head->next;
            head->next = head->child;
            head->next->prev = head;
            head->child = nullptr;
        }
        head = head->next;
    } 
    
    if(head and head->child) {
        (void)flatter(head->child, head->next);
        head->next = head->child;
        head->next->prev = head;
        head->child = nullptr;                
    }
    
    return(head);
}
    
    
    
    Node* flatten(Node* head) {
        //Node* ret = head;
        
        if(head == nullptr) {
            return(nullptr);
        }
        
        if(head->child == nullptr && head->next == nullptr){
            return head;
        }
        
        (void)flatter(head, nullptr);
        return(head); 
    }
};
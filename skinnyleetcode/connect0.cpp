/*
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node* head = root;

        while(head) {
            Node* temp = new Node(0);
            Node* node = temp;
            while(head) {
                if(head->left) {
                    node->next = head->left;
                    node = node->next;
                }
                if(head->right){
                    node->next = head->right;
                    node = node->next;
                }
                head = head->next;
            }
            head = temp->next;
        }

        return root;
    }
    Node* connect0(Node* root) {
        if(root == nullptr) return nullptr;
        
        std::queue<Node*> queue;
        queue.push(root);
        while(not queue.empty()) {
            int s = queue.size();
            while(s) {
                Node* front = queue.front(); queue.pop();
                if(front->left) queue.push(front->left);
                if(front->right) queue.push(front->right);
                s--;
                if(s) { front->next = queue.front(); }
                else { front->next = nullptr; }
            }
        }
        return root;
    }
};
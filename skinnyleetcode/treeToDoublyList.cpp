/*
 *  https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* lefty;
    Node* righty;
    
    void traverse(Node* root) {
        if(root) {
            traverse(root->left);
            printf("%d ", root->val);
            traverse(root->right);
        }
    }
    
    void min_max(Node* root, Node** min_node, Node** max_node) {
        if(root) {
            *min_node = (root->val < (*min_node)->val) ? root : *min_node;
            *max_node = (root->val > (*max_node)->val) ? root : *max_node;
            min_max(root->left, min_node, max_node);
            min_max(root->right, min_node, max_node);
        }
    }
    
    void tranform(Node* root, Node* predecessor, Node* successor) {
        
    }
    
    Node* treeToDoublyList1(Node* root) {
        traverse(root); printf("\n");
        Node* min_node = root;
        Node* max_node = root;
        min_max(root, &min_node, &max_node);
        printf("%p %p %d, %p %d\n", root, min_node, min_node->val, max_node, max_node->val);
        Node* predecessor = root->left;
        Node* successor = root->right;
        //tranform(root, predecessor, successor)
        return root;
    }
    
    
    Node* first = nullptr;
    Node* last = nullptr;
    
    void dfs(Node* root) {
        if(root) {
            dfs(root->left);
            if(last == nullptr) {
                first = root;
            }
            else {
                last->right = root;
                root->left = last;
            }
            last = root;
            dfs(root->right);
        }
    }
    
    Node* treeToDoublyList2(Node* root) {
        if(root == nullptr) return nullptr;
        dfs(root);
        last->right = first;
        first->left = last;
        return first;
    }
    
    void tree_to_vec(Node* root, std::vector<Node*>& vec) {
        if(root) {
            tree_to_vec(root->left, vec);
            vec.push_back(root);
            tree_to_vec(root->right, vec);
        }
    }
    
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        
        std::vector<Node*> vec;
        tree_to_vec(root, vec);
        int size = vec.size();
        for(int i = 0; i < size-1; i++) {
            vec[i]->right = vec[i+1];
            vec[i+1]->left = vec[i];
        }
        vec[0]->left = vec[size-1];
        vec[size-1]->right = vec[0];
        return vec[0];
    }
};
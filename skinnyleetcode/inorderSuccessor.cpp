/*
 *  https://leetcode.com/problems/inorder-successor-in-bst-ii/submissions/
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
    Node* parent;
};
*/

class Solution {
public:
    void traverse11(Node* root, std::vector<Node*>& vec) {
        if(root) {
            traverse11(root->left, vec);
            vec.push_back(root);
            traverse11(root->right, vec);
        }
    }
    Node* succ = nullptr;
    void traverse1(Node* root) {
        if(root) {
            traverse1(root->left);
            succ = root->right;
            return;
        }
        
    }
    Node* inorderSuccessor1(Node* node) {
        std::vector<Node*> vec;
        traverse11(node, vec);
        //Node* ans=nullptr;
        ///printf("%d %d\n", node->val, vec.size());
        for(int i = 0; i < vec.size(); i++) {
           // printf("%d %p %d\n", i, vec[i], vec[i]->val);
            if(vec[i]==node) {
                if(i+1 < vec.size()) {
                    return vec[i+1];
                }
            }
        } 
        
        return nullptr;

    }
    void traverse(Node* root, std::vector<Node*>& vec) {
        if(root) {
            traverse(root->left, vec);
            //printf("%d " , root->val);
            vec.push_back(root);
            traverse(root->right, vec);
        }
    }
    Node* inorderSuccessor(Node* node) {
        std::vector<Node*> vec;
        Node* node1 = node;
        if(not node1->right) while(node1->parent) node1=node1->parent;
        traverse(node1, vec);
        
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i]==node) {
                if(i+1 < vec.size()) return vec[i+1];
                else break;
            }
        } 
        return nullptr;
    }
    
    Node* inorderSuccessor2(Node* node) {
        if(node->right) {
            node=node->right;
            while(node->left) node=node->left;
            return node;
        }
        
        while(node->parent and node == node->parent->right) node=node->parent;
        return node->parent;
    }
    
    
};
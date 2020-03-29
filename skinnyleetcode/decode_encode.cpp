/*
 *  https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    /*
    TreeNode* search(TreeNode* root, TreeNode* node) {
        if(root == nullptr or root == node) return(root);
        
        return(search(root->left ))
        
    }
    */

    TreeNode* encode1(Node* root) {
        TreeNode* root1 = nullptr;
        if(root) {
            std::deque<std::pair<TreeNode*, Node*>> queue;
            root1 = new TreeNode(root->val);
            queue.push_back(std::make_pair(root1, root));
            while(not queue.empty()) {
                std::pair<TreeNode*, Node*> front = queue.front();
                TreeNode* binary_node = front.first;
                Node*     nray_node   = front.second;
                queue.pop_front();
                for(Node* child: nray_node->children) {
                    TreeNode* new_node = new TreeNode(child->val);
                    if(not binary_node->left) {
                        binary_node->left = new_node;
                    }
                    else {
                        binary_node->right = new_node;
                        binary_node = binary_node->right;


                    }
                    queue.push_back(std::make_pair(new_node, child));
                }
            }
        }
        return(root1);
    }
             /*   
                int size = queue.size();
                int s = 0;
                while(s <size) {
                    auto front = queue.front();
                    TreeNode* temp = new TreeNode(front.first->val);
                    for(Node* child: front.first->children) {
                        queue.push_back(std::make_pair(child, temp));
                    }
                    s++;
                    printf("%d ", front.first->val);
                    if(front.second == null) {
                        root1 = temp;
                    }
                    else {
                        root2 = root1;
                        while(root2 != front.second) {
                            root2 = root
                        }
                        if(not root2->left) root2->left = temp;
                        else {
                            
                        }
                    }
                    */
                    /*
                    if(not root1) {
                        root1 = temp;
                        root2 = root1;
                    }
                    else {
                        if(not root1->left) root1->left = temp;
                        else {
                            while(root1->right) {
                                root1 = root1->right;
                            }
                            root1->right = temp;
                        }
                    }
                    */
                    /*
                    queue.pop_front();
                }
                printf("\n");
            }
            */
      //  }
        
    //}

    // Decodes your binary tree to an n-ary tree.
    Node* decode1(TreeNode* root) {
        Node* root1 = nullptr;
        if(root) {
            std::deque<std::pair<Node*, TreeNode*>> queue;
            root1 = new Node(root->val);
            queue.push_back(std::make_pair(root1, root));
            while(not queue.empty()) {
                std::pair<Node*, TreeNode*> front = queue.front();
                Node*     nray_node   = front.first;
                TreeNode* binary_node = front.second;
                queue.pop_front();
                
                while(binary_node->left or binary_node->right) {
                    Node* new_node = nullptr;
                    if(not binary_node->left) {
                        new_node = new Node(binary_node->left->val);
                        nray_node->children.push_back(new_node);
                        queue.push_back(std::make_pair(new_node, binary_node->left));
                    }
                    else if(not binary_node->right) {
                        new_node = new Node(binary_node->right->val);
                        nray_node->children.push_back(new_node);
                        queue.push_back(std::make_pair(new_node, binary_node->right));
                        binary_node = binary_node->right;
                    }   
                }
                
            }
        }
        return(root1);
    }
    
    
    void bfs(TreeNode* root) {
        if(root) {
            std::deque<TreeNode*> q;
            q.push_back(root);
            while(not q.empty()) {
                int size = q.size();
                int s = 0;
                
                
                while(s < size) {
                    TreeNode* front = q.front();
                    if(front->left) q.push_back(front->left);
                    if(front->right) q.push_back(front->right);
                    s++;
                    printf("%d ", front->val);
                    q.pop_front();
                }
                printf("\n");
            }
        }
    }
    
    TreeNode* encode(Node* root) {
        if(root == nullptr) return(nullptr);
        
        TreeNode* root1 = new TreeNode(root->val);
        
        if(root->children.size() > 0) {
            root1->left = encode(root->children.front());
        }
        
        TreeNode* sibling = root1->left;
        for(int i = 1; i < root->children.size(); i++) {
            sibling->right = encode(root->children[i]);
            sibling = sibling->right;
        }
        
        if(root1->val == 1) bfs(root1);
        
        return(root1);
    }
    
    Node* decode(TreeNode* root) {
        if(root == nullptr) return(nullptr);
        
        Node* root1 = new Node(root->val);
        TreeNode* sibling = root->left;
        while(sibling != nullptr) {
            root1->children.push_back(decode(sibling));
            sibling = sibling->right;
        }
        
        return(root1);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
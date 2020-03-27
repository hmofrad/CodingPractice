/*
 *  https://leetcode.com/problems/n-ary-tree-postorder-traversal/submissions/
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
class Solution {
public:
    std::vector<int> vec;
    
    vector<int> dfs(Node* root) {
        std::vector<int> path;
        if(root) {
            std::vector<Node*> stack;
            stack.push_back(root);
            while(not stack.empty()) {
                auto node = stack.back();
                path.push_back(node->val);
                stack.pop_back();
                for(auto child: node->children) {
                    stack.push_back(child);
                }
            }
        }
        std::reverse(path.begin(), path.end());
        return(path);
    }
    
    void postorder1(Node* root) {
        if(root) {
            for(auto v: root->children) {
                //printf("%d ", v->val);
                postorder(v);
                //vec.push_back(v->val);
                
            }
            vec.push_back(root->val);
        }
    }
    
    vector<int> postorder(Node* root) {
        return(dfs(root));
        //postorder1(root);
        //return(vec);
    }
};
/*
 *  https://leetcode.com/problems/maximum-depth-of-n-ary-tree/solution/
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
    int maxDepth(Node* root) {
        if(not root) return 0;
        
        int d = 1;
        for(Node* child: root->children) {
            d = max(d, maxDepth(child)+1);
        }
        return(d);
    }
};
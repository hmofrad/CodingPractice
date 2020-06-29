/*
 * https://leetcode.com/problems/clone-graph/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
/*
    void clone0(Node* head, Node* node, std::unordered_set<Node*>& set) {
        if(node == nullptr) return;
        if(set.insert(node).second == false) return;
        
        head->val = node->val;
        int nneighbors = node->neighbors.size();
        
        
        head->neighbors.resize(nneighbors);
        
        for(int i = 0; i < nneighbors; i++) { head->neighbors[i] = new Node(0); } 
        
        for(int i = 0; i < nneighbors; i++) {
            clone0(head->neighbors[i], node->neighbors[i], set);
        }
    }
    
    Node* clone(Node* node, std::unordered_map<Node*, Node*>& map) {
        if(node == nullptr) return nullptr;

        
        Node* head = new Node(node->val);
        map[node]=head;
        printf("1.%d\n", head->val);
        for(Node* neighbor: node->neighbors) {
            
            if(map.count(neighbor) == 0 or map[neighbor] != head) {
                printf(" 2.%d %d\n", head->val, neighbor->val);
                head->neighbors.push_back(nullptr);
                head->neighbors.back() = clone(neighbor, map);
            }
        }
        return head;
    }
    */
    std::unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(map.count(node)) return map[node];
        
        int val = node->val;
        int nnodes = node->neighbors.size();
        Node* head = new Node(val);
        head->neighbors.resize(nnodes);
        map[node]=head;
        for(int i = 0; i < nnodes; i++) {
            Node* neighbor = node->neighbors[i];
            head->neighbors[i] = cloneGraph(neighbor);
        }
        
        return head;
    }
};
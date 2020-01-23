/*
 *  Problem: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 *  Compile: g++ -o levelOrder levelOrder.cpp -std=c++11 -g -Wall -fsanitize=address && ./levelOrder
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> order;
    if(root == nullptr) return order;
    std::vector<Node*> queue;
    queue.insert(queue.end(), root->children.begin(), root->children.end());
    int numChildrenThisLevel = root->children.size();
    int numChildrenNextLevel = 0;
    printf("%d\n", root->val);
    order.push_back({root->val});
    std::vector<int> nodesThisLevel;
    while(!queue.empty()) {
        printf("%d\n", queue.front()->val);
        if(!queue.front()->children.empty()) {
            queue.insert(queue.end(), queue.front()->children.begin(), queue.front()->children.end());
            numChildrenNextLevel += queue.front()->children.size();
        }
        nodesThisLevel.push_back(queue.front()->val);
        queue.erase(queue.begin());         
        numChildrenThisLevel--;
        if(!numChildrenThisLevel) {
            numChildrenThisLevel = numChildrenNextLevel;
            numChildrenNextLevel = 0;
            order.push_back(nodesThisLevel);
            nodesThisLevel.clear();
            nodesThisLevel.shrink_to_fit();
        }
            
    }
    
    return(order);    
}

int main(int argc, char **argv){
    Node* child11 = new Node(5);
    Node* child12 = new Node(6);
    
    Node* child1 = new Node(3, {child11, child12});
    Node* child2 = new Node(2);
    Node* child3 = new Node(4);
    Node* root = new Node(1, {child1, child2, child3});
    
    printf("%d [%d [%d %d] %d %d]\n", 
      root->val, 
        root->children[0]->val, 
          root->children[0]->children[0]->val, root->children[0]->children[1]->val,
        root->children[1]->val, root->children[2]->val);
    
    std::vector<std::vector<int>> order = levelOrder(root);
    
    for(auto l: order) {
        for(auto i: l) {
            printf("%d ", i);
        }
        printf("\n");
    }
    
    
    delete(child11);
    delete(child12);
    delete(child1);
    delete(child2);
    delete(child3);
    delete(root);
    return(0);
}







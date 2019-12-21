/*
 *  Cracking the coding interview: Problem 4.4: Convert a binary tree of depth D into D linked list (a linked list for each level)
 *  Compile & run: g++ -o binaryTreetoLinkedlist binaryTreetoLinkedlist.cpp -g -Wall -std=c++11 -fsanitize=address  && ./binaryTreetoLinkedlist
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

struct Node{
    Node(){};
    Node (int value_) : value(value_), left(nullptr), right(nullptr) {};
    int value;
    Node* left;
    Node* right;
};

struct ListNode{
    ListNode(){};
    ListNode (int value_) : value(value_), next(nullptr) {};
    int value;
    ListNode* next;
};


void traverse(struct Node* bst) {
    if(bst) {
        traverse(bst->left);
        printf("%d ", bst->value);
        traverse(bst->right);
    }
}
/*
std::vector<std::vector<int>> convert(struct Node* bst) {
    std::vector<std::vector<int>> queues;
    int d = 0;
    
    std::deque<struct Node*> q;
    
    if(bst) {
        q.push_back(bst);
        while(!q.empty()) {
            printf("[%d %d] ", q.front()->value, d);
            if(q.front()->left)
                q.push_back(q.front()->left);
            if(q.front()->right)
                q.push_back(q.front()->right);
            q.pop_front();
            d++;
            queues.push_back({d});
        }
        printf("\n");
    }
    
    for(auto q: queues) {
        for(auto d: q) {
            printf("%d ", d);
        }
        printf("\n");
    }
    
    return(queues);
}
*/

std::vector<std::vector<int>> convert(struct Node* bst) {
    std::vector<std::vector<int>> queues;
    
    
    std::deque<struct Node*> q;
    
        std::vector<int> queue;
        queue.push_back(bst->value);
        queues.push_back(queue);
        q.push_back(bst);
        while(!q.empty()) {
            std::vector<int> queue;
            for(auto qq: q) {
                if(qq->left) {
                    q.push_back(qq->left);
                    queue.push_back(qq->left->value);
                }
                if(qq->right) {
                    q.push_back(qq->right);
                    queue.push_back(qq->right->value);
                }
                q.pop_front();
            }
            queues.push_back(queue);
        }
    
    
    for(auto q: queues) {
        for(auto qq: q) {
            printf("%d ", qq);
        }
        printf("\n");
    }
    
    return(queues);
}


/*
           8
    3            10
1       6              14
      4   7      13
*/


int main(int argc, char** argv) {
    std::vector<int> array = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    struct Node* bst = new Node(8);
    bst->left = new Node(3);
    bst->left->left = new Node(1);
    bst->left->right = new Node(6);
    bst->left->right->left = new Node(4);
    bst->left->right->right = new Node(7); 
   
    bst->right = new Node(10);
    bst->right->right = new Node(14);
    bst->right->right->left = new Node(13);
    
   
    traverse(bst); printf("\n");
    
    std::vector<std::vector<int>> queues = convert(bst);
    
    delete bst->left->right->right; 
    delete bst->left->right->left;
    delete bst->left->right;
    delete bst->left->left;
    delete bst->left;
    
    delete bst->right->right->left;
    delete bst->right->right;
    delete bst->right;
    delete bst;
    
    return(0);
}
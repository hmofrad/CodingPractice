/*
 *  Cracking the coding interview: Problem 17.13: Convert a bst to linkedlist
 *  Compile & run: g++ -o bstToLinkedList bstToLinkedList.cpp -g -Wall -std=c++11 -fsanitize=address  && ./bstToLinkedList
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

struct BiNode {
    BiNode(int value_) : node1(nullptr), node2(nullptr), value(value_) {};
    struct BiNode* node1;
    struct BiNode* node2;
    int value;    
};

void traverse(struct BiNode* bst) {
    if(bst) {
        traverse(bst->node1);
        printf("%d ", bst->value);
        traverse(bst->node2);
    }
}


struct NodePair {
    NodePair(BiNode* head, BiNode* tail) {
        this->head = head;
        this->tail = tail;
    }
    struct BiNode* head;
    struct BiNode* tail;
};

struct NodePair* convert(BiNode* root) {
    if(root == nullptr) {
        return(nullptr);
    }
    
    struct NodePair* part1 = convert(root->node1);
    struct NodePair* part2 = convert(root->node2);
    
    if(part1 != nullptr) {
        part1->tail->node2 = root;
        root->node1 = part1->tail;
    }
    
    if(part2 != nullptr) {
        root->node2 = part2->head;
        part2->head->node1 = root;
    }
    printf("3.%d\n", root->value);
    return(new NodePair((part1 == nullptr) ? root : part1->head, 
                        (part2 == nullptr) ? root : part2->tail));
}

void traverse_q(struct BiNode* head) {
    while(head) {
        printf("%d ", head->value);
        head = head->node2;
    }
    printf("\n");
}


/*
           8
    3            10
1       6              14
      4   7      13
*/

int main(int argc, char** argv) {
    std::vector<int> array = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    struct BiNode* bst = new BiNode(8);
    bst->node1 = new BiNode(3);
    bst->node1->node1 = new BiNode(1);
    bst->node1->node2 = new BiNode(6);
    bst->node1->node2->node1 = new BiNode(4);
    bst->node1->node2->node2 = new BiNode(7); 
   
    bst->node2 = new BiNode(10);
    bst->node2->node2 = new BiNode(14);
    bst->node2->node2->node1 = new BiNode(13);
    
   
    traverse(bst); printf("\n");
    
    struct NodePair* head = convert(bst);
    printf("---------------\n");
    traverse_q(head->head);
    
    
    delete bst->node1->node2->node2; 
    delete bst->node1->node2->node1;
    delete bst->node1->node2;
    delete bst->node1->node1;
    delete bst->node1;
    
    delete bst->node2->node2->node1;
    delete bst->node2->node2;
    delete bst->node2;
    delete bst;
    
    return(0);
}
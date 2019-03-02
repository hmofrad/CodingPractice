/*
 *  Compile & Execute: g++ -o maxDepth maxDepth.cpp -std=c++11 && ./maxDepth
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <string.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
void traverse(TreeNode* root, int depth, int& maxDepth) {
    if(root == NULL)
        return;
    else {
        if(not(root->left and root->right)) {
            //depths.push_back(depth);
            if(depth > maxDepth)
                maxDepth = depth;
        }
    }
    
    //path.push_back(root->val);
    //printf("%d %d %d\n", root->val, depth, maxDepth);
    //if(not(root->left and root->right))
    depth++;
    traverse(root->left, depth, maxDepth);
    //printf("%d ", root);
    traverse(root->right, depth, maxDepth);
   // return(depth);
    
}

int maxDepth(TreeNode* root) {
    if(not root)
        return(0);
    std::vector<int> path;
    std::vector<int> depths;
    int maxDepth = 0;
    int depth = 1;
    traverse(root, depth, maxDepth);
    //maxDepth = depths.back();
    //std::vector<int>::iterator distance = std::max_element(depths.begin(), depths.end());
    //maxDepth = std::distance(depths.begin(), distance);
    //std::cout << std::distance(depths.begin(), distance) << std::endl;
    //for(int p: path) 
    //    printf("%d ", p);
    //printf("\n");
    
    //for(int p: depths) 
    //    printf("%d ", p);
    //printf("\n");
    
    return(maxDepth);
}


int main(int argc, char** argv) {
    //std::vector<std::vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    /*
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    //[3,9,20,null,null,15,7]
    printf("maxDepth=%d\n", maxDepth(root));
    return(0);
}
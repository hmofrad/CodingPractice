/*
 *  Problem: https://leetcode.com/problems/path-sum-iii/
 *  Compile: g++ -o pathSum pathSum.cpp -std=c++11 -g -Wall -fsanitize=address && ./pathSum
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root) {
    if(root) {
        printf("%d ", root->val);
        traverse(root->left);
        traverse(root->right);
    }
}

void traverse1(TreeNode* root, int my_sum, int sum, int* count) {
    if(root) {
        if((my_sum + root->val) >  sum) {
            my_sum = root->val;
            printf("No %d %d\n", root->val, my_sum);
            
        }
        else if ((my_sum + root->val) == sum) {
            printf("Yes %d\n", root->val);
            my_sum = root->val;
            *count = *count + 1;
        }
        else {
            
            my_sum += root->val;
            printf("N/A %d %d\n", root->val, my_sum);
        }
        //printf("%d ", root->val);
        traverse1(root->left, my_sum, sum, count);
        traverse1(root->right, my_sum, sum, count);
    }
}

int pathSum(TreeNode* root, int sum) {
    int count = 0;
    traverse1(root, 0, sum, &count);
    return(count);    
}



/*
       5
     /     \
    4        8
   /         / \
  11        13  4
 / \       /\
7  2       5  1
*/

/*
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

*/

int main(int argc, char **argv){
    struct TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(5);
    root->right->left->right = new TreeNode(1);
    int sum = 22;
    
    /*
    struct TreeNode* root = new TreeNode(10);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    int sum = 8;
    */
    
    traverse(root);
    printf("\n");
    
    
    int count = pathSum(root, sum);
    printf("count=%d\n", count );
    
    return(0);
}







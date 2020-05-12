/*
 *	https://leetcode.com/problems/print-binary-tree/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



std::vector<std::vector<int>> bfs1(TreeNode* root) {
	if(root==nullptr) return std::vector<std::vector<int>>();
	std::vector<std::vector<int>> vec;
	std::queue<TreeNode*> queue;
	queue.push(root);
	while(not queue.empty()) {
		int size = queue.size();
		std::vector<int> v;
		while(size) {
			TreeNode* front = queue.front(); queue.pop();
			v.push_back(front->val);
			if(front->left) queue.push(front->left);
			if(front->right) queue.push(front->right);
			size--;
		}
		vec.push_back(v);
	}
	return vec;
}

/*
    1
   /
  2	
   \
    3
*/

int get_depth(TreeNode* root) {
	if(root==nullptr) return 0;
	return max(get_depth(root->left), get_depth(root->right)) + 1;
}	
	
	
	
void dfs(TreeNode* root, int index, int left, int right, vector<vector<string>>& mat) {
	if(root == nullptr) return;
	
	mat[index][(left+right)/2]=std::to_string(root->val);
	dfs(root->left, index+1, left, (left+right)/2, mat);
	dfs(root->right,index+1, (left+right+1)/2, right, mat);
}


vector<vector<string>> printTree(TreeNode* root) {
	if(root==nullptr) return std::vector<std::vector<string>>();
	int depth = get_depth(root);
	//int width = pow(2,depth)-1;
	int width = (1<<depth)-1;
	vector<vector<string>> mat(depth, std::vector<std::string>(width,""));
	dfs(root, 0, 0, width, mat);
	return mat;
}
    
    
int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(3);
	vector<vector<string>> vec = printTree(root);
	for(std::vector<string>& v: vec) {
            for(string s: v) printf("<%s>", s.c_str()); printf("\n");
	}
	return 0;
}
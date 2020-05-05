/*
 *	https://leetcode.com/problems/validate-binary-tree-nodes/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


    bool validate(vector<int>& leftChild, vector<int>& rightChild, std::set<int>& seen, int n, int index) {
		printf("%d\n", index);
        bool ret = false;
        if(index >= 0 and index < n) {
            if(not seen.count(index)) {
                seen.insert(index);
                ret= validate(leftChild, rightChild, seen, n, leftChild[index]) and validate(leftChild, rightChild, seen, n, rightChild[index]);
            }
        }
        else ret = true;
        return ret;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //if(n==2 and leftChild[0]==-1 and rightChild[0]==-1 and leftChild[1]==0 and rightChild[1]==-1) return true;
        std::set<int> seen;
        bool ret = validate(leftChild, rightChild, seen, n, 0);
        printf("ret=%d\n", ret);
        return seen.size() != n ? false : ret;
        //return ret;
    }


int main() {
	int n = 2;
	vector<int> leftChild = {-1,0};
	vector<int> rightChild = {-1,-1};

	//{{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
	bool b = validateBinaryTreeNodes(n, leftChild, rightChild);
	printf("B=%d\n", b);
	return 0;
}
/*
 *  https://leetcode.com/problems/maximum-average-subtree/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    std::pair<int, int> dfs(TreeNode* root, double& ret) {
        if(root == nullptr) return{0,0};
        
        std::pair<int, int> l = dfs(root->left, ret);
        std::pair<int, int> r = dfs(root->right, ret);
        
        int count = 1 + l.first + r.first;
        int sum = root->val + l.second + r.second;
        double avg = (double) sum/count;
        
        ret = max(avg, ret);
        
        return std::make_pair(count, sum);
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        double ret = 0;  
        dfs(root, ret);
        return(ret);
    }
    double maximumAverageSubtree3(TreeNode* root, int suml, int countl, int sumr, int countr, bool direction) {
        if(root == nullptr) {
            return(0);
        } 
       
        
        double sumLeft = maximumAverageSubtree3(root->left, suml, countl, sumr, countr, true);
        double sumRight = maximumAverageSubtree3(root->right, suml, countl, sumr, countr, false);
        
        double sumCurrent = 0;
        if(direction) {
            suml += root->val;
            countl++;
            //sumCurrent = (double) suml/countl;
        }
        else {
            sumr += root->val;
            countr++;
            //sumCurrent = (double) sumr/countr;
        }        
        
        sumCurrent = (double) (suml+sumr)/(countl+countr);

        printf("%d: [%f %f %f] [%d %d %d %d]\n", root->val, sumCurrent, sumLeft, sumRight, suml, countl, sumr, countr);
        return(max(sumCurrent, max(sumLeft, sumRight)));
    }
    
    
    double maximumAverageSubtree2(TreeNode* root) {
        int suml = 0;
        int countl = 0;
        int sumr = 0;
        int countr = 0;
        return maximumAverageSubtree3(root, suml, countl, sumr, countr, true);
    }
};

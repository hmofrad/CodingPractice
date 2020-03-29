/*
 *  https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/submissions/
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
    std::vector<int> values;
    std::vector<int> levels;
    int values_pos = 0;
    int levels_pos = 0;
    //std::vector<std::vector<int>> levels;
    //std::vector<std::vector<bool>> direction;
    /*
    TreeNode* addNode(TreeNode* root, int value, int level) {
        //if(root == nullptr) root = new TreeNode(value);

        if(not root->left and level-1 == 0) {
            root->left = new TreeNode(value);
            return;
        }
        else if(not root->right and level-1 == 0) {
            root->right = new TreeNode(value);
            return;
        }
        
        if(root->left and level-1 != 0) {
            addNode(root->left, value, level-1);
        }
        else {
            addNode(root->right, value, level-1);
        }
    
    }
    */
    TreeNode* buildTree(int level) {
        if(values_pos >= values.size() or levels_pos >= levels.size() or level != levels[levels_pos]) {
            return(nullptr);
        }
        TreeNode* root = new TreeNode(values[values_pos]);
        values_pos++;
        levels_pos++;
        root->left = buildTree(level+1);
        root->right = buildTree(level+1);
        return(root);
    }


    TreeNode* preorder2vector(string S) {
        TreeNode* root = nullptr;
        int s = S.length();
        int i = 0;
        int j = 0;
        //int d = 0;
        //int ii = 0;
        while(i < s) {
            j = i;
            while(j < s and S[j] == '-') {
                j++;
            }
            int level=j-i;
            //printf("i=%d j=%d level=%d---", i, j, level);
            i = j;
            while(j < s and S[j] != '-') {
                j++;
            }
            int length = 0;
            if(j != s) length = j-(i-1)+1;
            else length = j-i+1;
            std::string value_str = S.substr(i, length);
            //printf("i=%d j=%d length=%d str=%s\n", i, j, length, value_str.c_str());
            int value_int = std::stoi(value_str);
            //printf("V=%d D=%d\n", value_int, level);
           // printf("V=%s %d %d %d\n", value_str.c_str(), d, i, j);
            //if(not root) root = new TreeNode(value_int);
            //else addNode(root, value_int, level);
            values.push_back(value_int);
            levels.push_back(level);
            /*
            if(levels.empty()) {
                //printf("1.%d\n", value_int);
                std::vector<int> temp = {value_int};
                levels.push_back(temp);
            }
            else {
                //printf(">>>> 2.%d %d %d\n", value_int, levels.size(), level);
                if(levels.size() <= level) {
                    std::vector<int> temp = {value_int};
                    levels.push_back(temp);
                }
                else {
                    levels[level].push_back(value_int);
                }
            }
            */
            //
            //
            i = j;
            //ii++;
            //if(ii == 3) break;
        }
        
        //for(int i = 0; i < values.size(); i++) {
        //    printf("%d %d\n", values[i], levels[i]);
        //}
        
        
        return(buildTree(0));
    }    
    
    TreeNode* recoverFromPreorder(string S) {
        //int s = S.length();
        //if(not s) return nullptr;
        
        //preorder2vector(S);
        /*
        for(auto level: levels) {
            for(auto lvl: level) {
                printf("%d ", lvl);
            }
            printf("\n");
        }
       */
        return(preorder2vector(S));
    }
};
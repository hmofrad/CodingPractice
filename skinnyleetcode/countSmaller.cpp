/*
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    struct Node {
        Node(int value_, int smaller_) : value(value_), smaller(smaller_) {left=nullptr; right=nullptr;}
        ~Node(){}
        int value;
        int smaller;
        struct Node* left;
        struct Node* right;
    };
    
    void insert(struct Node** root, int value, int& smaller) {
        //printf("%p %d %d\n", *root, value, smaller);
        if(*root==nullptr) {*root = new Node(value, 0);}
        else {
            if(value<(*root)->value) {
                (*root)->smaller++;
                insert(&((*root)->left), value, smaller);
            }
            else if(value==(*root)->value) {
                smaller+=(*root)->smaller;
                insert(&((*root)->right), value, smaller);
            }
            if(value>(*root)->value) {
                smaller+=(*root)->smaller+1;
                insert(&((*root)->right), value, smaller);
            }
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        //nums={-1,-1};
        int size = nums.size();
        vector<int> counts(size);
        Node* root = nullptr;
        for(int i = size-1; i>=0; i--) {
          //  printf("%d\n", i);
            insert(&root, nums[i], counts[i]);
        }
        return counts;
    }
    vector<int> countSmaller2(vector<int>& nums) {
        std::map<int, int> map;
        int size = nums.size();
        vector<int> counts(size);
        for(int i = size-1; i>=0; i--) {
            int key = nums[i];
            map[key]++;
            auto it = map.find(key); 
            //for(auto it1 = map.begin(); it1 != it;it1++) {  counts[i]+=it1->second; }
            //printf("[%d]=%d, %d\n", i, nums[i], *map.upper_bound(key));
        }
        return counts;
    }
    vector<int> countSmaller1(vector<int>& nums) {
        int size = nums.size();
        vector<int> counts(size);
        for(int i = size-1; i>=0; i--) {
            for(int j=i+1; j<size; j++) {
                if(nums[j]<nums[i]) counts[i]++;
            }
        }
        return counts;
    }
};
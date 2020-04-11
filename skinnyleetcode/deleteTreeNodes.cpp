/*
 *  https://leetcode.com/problems/delete-tree-nodes/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        for(int i = nodes-1; i > 0; i--) {
            value[parent[i]] += value[i];
        }
        
        int res = nodes;
        for(int i = 1; i < nodes; i++) {
            if((value[i] == 0) or (value[parent[i]] == 0)) {
                res--;
                value[i] = 0;
            }
        }
        return res - not value[0];
    }
    
    
    
    bool isLeaf(vector<int> parent, int index) {
        bool tf = true;
        int size = parent.size()-1;
        for(int i = size; i > 0; i--) {
            if(parent[i] == index) {
                tf = false;
                break;
            }
        }
        //printf("%d %d\n", tf, index);
        return(tf);
    }
    
    void func(int nodes, vector<int>& parent, vector<int>& value, int index, int& nodes_left) {
        if(index == 0) {if(value[index] == 0) nodes_left-=1; return;}
            
        int p = parent[index];
        int sum = 0;
        int zero_nodes = 0;
        int num_nodes = 0;
        int i = index;
        while(i>=1 and parent[i] == p) {
            sum += value[i];
            if(value[i] == 0 and isLeaf(parent, i)) {nodes_left--; num_nodes--;}
            i--;
            num_nodes++;
        }
        value[p] += sum;
        if(value[p] == 0) {
            nodes_left -= (num_nodes + 1);
        }
        //nodes_left -= zero_nodes;
        func(nodes, parent, value, i, nodes_left);
        
    }
    
    int deleteTreeNodes1(int nodes, vector<int>& parent, vector<int>& value) {
        int nodes_left = nodes;
        func(nodes, parent, value, nodes-1, nodes_left);
        
        // for(int i = 0; i < nodes; i++) {
        //    printf("%d ", value[i]);
        //}
        //printf("\n");
        
        return(nodes_left);
    }
        /*
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int parent1 = parent[nodes-1];
        int sum = 0;
        for(int i = nodes-1; i > 1; i--) {
            if(parent[i] == parent1) {
                if(value[i] == 0) {
                    parent[i] = -2;
                }
                sum +=value[i];
            }
            else {
                value[parent1] += sum;
                if(value[parent1] == 0) parent[parent1]=-2;
                printf("%d %d %d\n", i+1, sum, value[parent1]);
                parent1 = parent[i];
                sum = value[i];
            }
        }
        
        for(int i = 0; i < nodes; i++) {
            printf("%d ", parent[i]);
        }
        printf("\n");
        
        return(0);
    }
        */
};
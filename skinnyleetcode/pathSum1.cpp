/*
 *	https://leetcode.com/problems/path-sum-iv/solution/	
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    std::vector<int> init_tree(int n) {
        return std::vector<int>(n,-1);
    }
    
    int bfs(std::vector<int>& tree) {
        int path_sum = 0;
        std::queue<std::pair<int,int>> queue;
        queue.push({1, 0});
        while(not queue.empty()) {
            int size = queue.size();
            while(size) {
                std::pair<int, int> front = queue.front(); queue.pop();
                
                std::vector<int> nodes=get_nodes(tree, front.first);
                if(front.first==8) {
                    printf("%d %d\n", nodes[0], nodes[1]);
                //    break;
                }
                //printf("[%d %d]:[%d %d] [%d %d]\n", front.first, front.second, nodes[0], tree[nodes[0]], nodes[1], tree[nodes[1]]);
                if(nodes[0]!=-1 and tree[nodes[0]]!=-1) { queue.push({nodes[0], tree[front.first]+front.second}); }
                if(nodes[1]!=-1 and tree[nodes[1]]!=-1) { queue.push({nodes[1], tree[front.first]+front.second}); }                
                if((nodes[0]==-1 or tree[nodes[0]]==-1) and (nodes[1]==-1 or tree[nodes[1]]==-1)) { path_sum += tree[front.first] + front.second;}

                size--;
            }
            //break;
        }
        return path_sum;
    }
    
    void insert_node(std::vector<int>& tree, int num) {
        int v = num%10; num/=10;
        int p = num%10; num/=10;
        int d = num;      
        int i = (1<<(d-1))+(p-1);
        //printf("(%d %d %d)->%d\n", d, p, v, i);
        tree[i]=v;
    }
    
    
    
    std::vector<int> get_nodes(std::vector<int>& tree, int i) {
        return (i<8) ? std::vector<int> {i*2, (i*2)+1} : std::vector<int>({-1,-1});
    }
                 
     void print(std::vector<int>& tree) {
         int n = tree.size();
         for(int i = 0; i < n; i++) {
            printf("%d ", tree[i]);
        }
        printf("\n");
     }
    
    int pathSum(vector<int>& nums) {
        int n = 1 << 4;
        std::vector<int> tree= init_tree(n);
        for(int& num: nums) insert_node(tree, num); 
        //print(tree);
        return bfs(tree);
         //return 0;
    }
};
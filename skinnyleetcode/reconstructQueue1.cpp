/*
 *  https://leetcode.com/problems/queue-reconstruction-by-height/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
 class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](std::vector<int> a, std::vector<int> b) {
            return(a[0] > b[0] or (a[0] == b[0] and a[1] < b[1]));
            
        });
        
        
        for(std::vector<int> a: people) {
            printf("[%d %d] ", a[0], a[1]);
        }
        printf("\n");
        
        
         vector<vector<int>> ans;
        for(int i=0;i<people.size();i++) {
            printf("[h=%d k=%d]: ", people[i][0], people[i][1]);
            ans.insert(ans.begin()+people[i][1], people[i]);
            for(std::vector<int> a: ans) {
                printf("[%d %d] ", a[0], a[1]);
            }
            printf("\n");
        }
        return ans;  

    }
    
    
    vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
        std::vector<std::vector<int>> ans;
        int ii = 0;
        while(not people.empty()) {
            int size_p = people.size();
            int min_k = people[0][1];
            for(int i = 1; i < size_p; i++) {
                if(people[i][1] < min_k) min_k = people[i][1];
            }
            
            std::vector<int> removed_indices;
            for(int i = 0; i < size_p; i++) {
                std::vector<int> p = people[i];
                if(p[1] == min_k) {
                    if(ans.empty()) {
                        ans.push_back(p);
                    }
                    else {
                        int size_a = ans.size();
                        ans.resize(size_a+1);
                        int k = size_a;
                        int b = 0;
                        int j = 0;
                        //while(p[0] <= ans[j][0] and b < ans[j]) {b++; j++;}

                        printf("p[%d %d] b=%d k=%d\n", p[0], p[1], b, k);
                        for(int j = size_a; j > k; j--) {
                            ans[j] = ans[j-1];
                        }
                        ans[k] = p;
                    }

                    removed_indices.push_back(i);
                }
            }
            
            int size_r = removed_indices.size();
            for(int i = 0; i < size_r; i++) {
                int j = removed_indices[i]-i;
                people.erase(people.begin()+j, people.begin()+j+1);
            }
            ii++;
            printf("i=%d", ii);
            for(std::vector<int> a: ans) {
                printf("[%d %d] ", a[0], a[1]);
            }
            printf("\n");
            
            if(ii==2) break;    
        }
        

        return(ans);
    }
};
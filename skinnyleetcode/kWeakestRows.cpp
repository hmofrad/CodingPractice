/*
 *  https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = (m) ? mat[0].size() : 0;
        std::vector<int> out(m);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) {
                    out[i] += mat[i][j];
                    //out[i] += (mat[i][j] * (int) pow(2, n-1-j));
                }
                else {
                    break;
                }
            }
        }
        
        std::map<int, std::deque<int>> map;
        for(int i = 0; i < m; i++) {
            map[out[i]].push_back(i);
        }
        /*
        for(auto o: out) {
            printf("%d ", o);
        }
        printf("\n");
        */
        
        std::sort(out.begin(), out.end());
        

        
        auto ptr = map.begin();
        int i = 0;
        std::vector<int> ans;
        while(i < k) {
            if(not ptr->second.empty()) {
                ans.push_back(ptr->second.front());
                ptr->second.pop_front();
                i++;
            }
            else {
                ptr++;
            }
        }
        
        //std::vector<int> sorted = out;
        //std::sort(sorted.begin(), sorted.end());
        
        
        
        
        return(ans);
    }
    
    
    //vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
    //}
    
    
};
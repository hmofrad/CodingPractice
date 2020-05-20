/*
 *	https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, function<bool(std::tuple<int, int, int> a, std::tuple<int, int, int> b)>> min_heap([](std::tuple<int, int, int> a, std::tuple<int, int, int> b) {return std::get<2>(a) > std::get<2>(b);});
        
        int n = matrix.size();
        for(int i = 0; i < min(n,k); i++) min_heap.push({i, 0, matrix[i][0]});
        int ans = -1;
        while(not min_heap.empty()) {
            int row, col, value;
            std::tie(row, col, value) = min_heap.top(); min_heap.pop();
            if(--k == 0) { ans = value; break; }
            if(++col<n) { value = matrix[row][col]; min_heap.push({row, col, value}); }
        }
        //priority_queue<State*,vector<State*>,function<bool(const State*,const State*)>> pq([](const State* s1, const State* s2){return s1->hValue>s2->hValue;});

    //        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;
//   std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
        
        //int nrows = matrix.size();
        //int ncols = (nrows) ? matrix[0].size() : 0;
        
        //if(nrows==1 and ncols==1) return matrix[0][0];
        
        //int r = k/nrows;
        //int c = (k%ncols)-1;
        //printf("%d %d %d %d", nrows, ncols, r, c);
        return ans;
    }
    
    
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
    std::vector<int> smallests(matrix.size());
    std::vector<uint32_t> indices(matrix.size());
    int smallest = 0;
    
    for(uint32_t i = 0; i < matrix.size(); i++) {
        smallests[i] = matrix[i][0];
    }
    
    
    for(int32_t l = 0; l < k; l++) {
        //for(uint32_t i = 0; i < matrix.size(); i++) {
          //  if(indices[i] < matrix[0].size()) {
            //    smallests[i] = matrix[i][indices[i]];
            //}
        //}
        
        uint32_t j = 0;
        while(indices[j] >= matrix[0].size()) {
            j++;
        }
        smallest = smallests[j];
        int index = j;
        for(uint32_t i = j; i < smallests.size(); i++) {
            if(smallests[i] < smallest) {
                smallest = smallests[i];
                index = i;
            }
        }
        indices[index]++;
        if(indices[index] < matrix[0].size()) {
            smallests[index] = matrix[index][indices[index]];
        }
    }
    return(smallest);   
    }
};
/*
 *  https://leetcode.com/problems/sum-of-even-numbers-after-queries/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int num_queries = queries.size();
        int A_size = A.size();
        std::vector<int> ans(num_queries);
        
        int sum = 0;
        for(int j = 0; j < A_size; j++) {
            if((A[j]%2) == 0)
                sum += A[j];
        }
        //printf("%d\n", sum);
        for(int i = 0; i < num_queries; i++) {
            int value = queries[i][0];
            int index = queries[i][1];
            
            int a1 = A[index];
            bool p1 = a1%2;
            A[index] += value;
            int a2 = A[index];
            bool p2 = a2%2;
            
            if(not p1 and not p2) sum += value;
            else if(p1 and not p2) sum += a2;
            else if(not p1 and p2) sum -= a1;
            //printf("1[%d %d] 2[%d %d] %d %d %d\n", a1, p1, a2, p2, (p1 and not p2), sum, value);
            ans[i] = sum;            
        }
        return(ans);
    }
};
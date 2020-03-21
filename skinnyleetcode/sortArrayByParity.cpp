/*
 *  https://leetcode.com/problems/sort-array-by-parity/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2019
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    vector<int> sortArrayByParity1(vector<int>& A) {
        std::vector<int> out;
        std::vector<int> out1;
        for(int i = 0; i < A.size(); i++) {
            if(A[i]%2)
                out1.push_back(A[i]);
            else 
                out.push_back(A[i]);
        }
        out.insert(out.end(), out1.begin(), out1.end());
        return(out);
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size()-1;
        while (i < j) {
            if((A[i]%2) > (A[j]%2)) {
                std::swap(A[i], A[j]);
            }
            
            if(not(A[i]%2)) i++;
            if(A[j]%2) j--;
        }
        return(A);
    }
    
};
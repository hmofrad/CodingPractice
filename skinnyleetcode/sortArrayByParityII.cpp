/*
 *  https://leetcode.com/problems/sort-array-by-parity-ii/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 class Solution {
public:
    vector<int> sortArrayByParityII1(vector<int>& A) {
        int m = A.size();
        int i = 0;
        //int j = (not((m-1)%2)) ? m-1 : m-2;
        //int k = ((m-1)%2) ? m-1 : m-2;
        int j = 0;
        int k = 1;
        
        std::vector<int> B(m);
        
        for(int i = 0; i < m; i++) {
            if((A[i]%2 and not(i%2)) or (A[i]%2 and i%2)) {
                B[k] = A[i];
                k += 2;
            }
           //else if((not(A[i]%2) and i%2) or (not(A[i]%2) and not(i%2))){
            else{
               B[j] = A[i];
                j += 2;
           }
        }
        
        /*
        while(j>=0 and k>=0) {
            if((A[i]%2 and not(i%2)) or (A[i]%2 and i%2)) {
                std::swap(A[i], A[j]);
                j-=2;
            }
            else if((not(A[i]%2) and i%2) or (not(A[i]%2) and not(i%2))){
                std::swap(A[i], A[k]);
                k-=2;
            }
        }
        */
        return(B);
    }
    vector<int> sortArrayByParityII(vector<int>& A) {
        int m = A.size();
        int j=1;
        for(int i = 0; i < m; i+=2) {
            if(A[i]%2) {
                while(A[j]%2) {
                    j+=2;
                }
                std::swap(A[i],A[j]);
            }
        }
        return(A);
    }
    
    
};
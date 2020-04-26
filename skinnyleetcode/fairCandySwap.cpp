/*
 *  https://leetcode.com/problems/fair-candy-swap/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sumA = std::accumulate(A.begin(), A.end(), 0);
        int sizeB = B.size();
        int sumB = std::accumulate(B.begin(), B.end(), 0);
        int sum =  sumA + sumB; 
        int delta = (sumB-sumA)/2;
        std::set<int> setB(B.begin(), B.end());
        
        std::vector<int> ans;
        for(int a: A) {
            if(setB.count(a+delta)) {ans={a, a+delta}; break;}
        }
        return ans;
    }
    vector<int> fairCandySwap1(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sumA = std::accumulate(A.begin(), A.end(), 0);
        int sizeB = B.size();
        int sumB = std::accumulate(B.begin(), B.end(), 0);
        int sum =  sumA + sumB; 
        int share = sum/2;
        int diff = sumA-sumB;
        std::vector<int> ans;
        for(int i = 0; i < sizeA; i++) {
            for(int j = 0; j < sizeB; j++) {
                //printf("%d %d %d %d\n",A[i], B[j], A[i]-B[j], diff);
                if(sumA-A[i]+B[j] == share and sumB-B[j]+A[i] == share) {ans = {A[i],B[j]}; return ans;}
            }
        }
        return ans;
    }
};
/*
 *  https://leetcode.com/problems/smallest-range-i/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
        int smallestRangeI1(vector<int>& A, int K) {
        std::sort(A.begin(), A.end());
        int m = A.size();
        std::vector<int> B(m, 0);
        
        for(int i = 0; i < m; i++) {
            //printf("A[%d]=%d, %d\n", i, A[i], A[m/2]/2);
            if(A[i] < A[m/2]/2) {
                int k = -K;
                //printf("%d %d\n", k);
                while(k < K and (A[i] + k < A[m/2]/2)) k++;
                //printf("%d k=%d\n", A[i], k);
                B[i] = A[i] + k;
            }
            else if(A[i] > A[m/2]/2) {
                int k = K;
                //printf("1.%d %d %d>>\n", A[i], k, A[i] - k );
                while(k > -K and A[i] - k > A[m/2]/2) {
                   // printf("%d ", A[i]-k);
                    k--;
                }
                //printf("\n<<2.%d k=%d\n", A[i], k);
                B[i] = A[i] + k;
            }
            else {
                B[i] = A[i];
            }
        }
        printf("\nB:");
        for(auto b: B) {
            printf("%d ", b);
        }
        printf("\n");
        std::sort(B.begin(), B.end());
        if(A==B) return(0);
            
            for(auto& a: A) {a +=K;}
        
        if(A==B) return(0);
            
        auto p = std::minmax_element(B.begin(), B.end());
        //printf("%d %d\n", *p.second, *p.first);
        return(*p.second - *p.first);
        
        //return(0);
    }
    
    
    int smallestRangeI(vector<int>& A, int K) {
        int mi = A[0];
        int ma = A[0];
        for(int a: A) {
            mi = (a < mi) ? a : mi;
            ma = (a > ma) ? a : ma;
        }
        return(max(0, ma-mi-2*K));
    }
    
    int smallestRangeI2(vector<int>& A, int K) {
        std::sort(A.begin(), A.end());
        int m = A.size();
        std::vector<int> B(m, 0);
        
        for(int i = 0; i < m; i++) {
           // printf("%d\n", i);
            if(A[i] < A[m/2]/2) {
                int k = -K;
                while(k <= K and A[i] + k < A[m/2]) k++;
                B[i] = A[i] + k;
            }
            else if(A[i] > A[m/2]) {
                int k = K;
                while(k <= K and A[i] - k > A[m/2]) k--;
                B[i] = A[i] + k;
            }
            else {
                B[i] = A[i];
            }
        }
        
        auto p = std::minmax_element(B.begin(), B.end());
        //printf("%d %d\n", *p.second, *p.first);
        return(*p.second - *p.first);
        
        //return(0);
    }
};
/*
 *  https://leetcode.com/problems/squares-of-a-sorted-array/solution/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int pivot = 0;
        int m = A.size();
        for(int i = 0; i < m; i++) {
            if(A[i] >= 0) {
                pivot = i;
                break;
            }
        }
        
        //if(pivot == m-1) return(A);
        
        int ir = pivot;
        int mr = m-1;
        int il = pivot-1;
        int ml = 0;
        
        int i = 0;
        std::vector<int> squares(m);
        while(ir <= mr and il >= ml) {
            int vr = A[ir] * A[ir];
            int vl = A[il] * A[il];
            //printf("%d R[%d]=%d L[%d]=%d\n", i, ir, vr, il, vl);
            if(vr == vl) {
                squares[i] = vr;
                squares[i+1] = vl;
                 i += 2;
                ir++;
                il--;
            }
            else if(vr < vl) {
                squares[i] = vr;
                 i++;
                ir++;
            }
            else {
                squares[i] = vl;
                i++;
                il--;
            }
        }
        
        while(ir <= mr) {
            squares[i] = A[ir] * A[ir];
            i++; 
            ir++;
        }
        
        while(il >= ml) {
            squares[i] = A[il] * A[il];
            i++; 
            il--;
        }
        
        return(squares);
    }
};
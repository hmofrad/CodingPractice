/*
 * https://leetcode.com/problems/squares-of-a-sorted-array/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size = A.size();
        int left = 0;
        int right = size-1;
        std::vector<int> ans(size); int i = size-1;
        while(left<=right){
            int x = A[left]*A[left];
            int y = A[right]*A[right];
            if(x>=y) { ans[i--]=x; left++; }
            else { ans[i--]=y; right--;}
        }
        return ans;
    }
    int linear_seach(std::vector<int>& A) {
        int mid = -1;
        int size = A.size();
        for(int i = size-1; i > 0; i--) {
            if(abs(A[i]) < abs(A[i-1])) {mid = i; break;}
        }
        return mid;
    }
    
    vector<int> sortedSquares2(vector<int>& A) {
        int mid = linear_seach(A);
        //int mid = binary_seach(A);
        int size = A.size();
        for(int i = size-1; i > 0; i--) {
            if(abs(A[i]) < abs(A[i-1])) {mid = i; break;}
        }
        //printf("%d\n", mid);
        std::vector<int> ans(size); int k = 0;
        int i0 = 0, j0 = mid-1;
        int i1 = mid, j1 = size-1;
        while(j0>=i0 and i1<=j1) {
            if(abs(A[j0])<=abs(A[i1])) {ans[k++]=A[j0]*A[j0]; j0--;}
            else {ans[k++]=A[i1]*A[i1]; i1++; }
        }
        while(j0>=i0) {ans[k++]=A[j0]*A[j0]; j0--;}
        while(i1<=j1) {ans[k++]=A[i1]*A[i1]; i1++;}
        
        return ans;
    }
    vector<int> sortedSquares1(vector<int>& A) {
        std::priority_queue<int> pq;
        for(int a: A) {pq.push(a*a);}
        int size = A.size();
        for(int i = size-1; i>=0; i--) {A[i] = pq.top(); pq.pop();}
        return A;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    vector<int> sortedSquares0(vector<int>& A) {
        
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

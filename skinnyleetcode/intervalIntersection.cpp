/*
 *  https://leetcode.com/problems/interval-list-intersections/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Solution {
public:
    vector<vector<int>> intervalIntersection1(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ia = 0;
        int ma = A.size();
        int ib = 0;
        int mb = B.size();
        std::vector<std::vector<int>> ans;
        while(ia < ma and ib < mb) {
            int low = max(A[ia][0],B[ib][0]);
            int high = min(A[ia][1],B[ib][1]);
            if(low<=high) ans.push_back({low, high});
            if(A[ia][1] < B[ib][1]) ia++;
            else ib++;
        }
        return(ans);
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ia = 0;
        int ma = A.size();
        int ib = 0;
        int mb = B.size();
        std::vector<std::vector<int>> ans;
        //printf("%d %d\n",ia, ib, ma, mb);
        while(ia < ma and ib < mb) {
            int al = A[ia][0];
            int ar = A[ia][1];
            int bl = B[ib][0];
            int br = B[ib][1];
            //printf("A[%d]={%d,%d}, B[%d]={%d,%d} ? %d\n", ia, al, ar, ib, bl, br, ar < bl);
            //if((al >= bl and al <= br) or (ar >= bl and ar <= br)) {
                //std::vector<int> temp = {al, bl, ar, br};
                //std::sort(temp.begin(), temp.end());
                
                int l = max(al, bl);
                int r = min(ar, br);
                if(l<=r)
                    ans.push_back({l, r});
            //}
            
            if(ar < br) ia++;
            else ib++;
        }
        return(ans);
    }
};
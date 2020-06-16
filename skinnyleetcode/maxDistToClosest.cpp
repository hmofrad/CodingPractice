/*
 * https://leetcode.com/problems/maximize-distance-to-closest-person/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int d = 0, size = seats.size(), j = -1;
        for(int i = 0; i < size; i++) {
            if(seats[i]==1) {
                d = j<0 ? i : max(d, (i-j)/2);
                j = i;
            }
        }
        
        return max(d, size-1-j);
    }
    int maxDistToClosest1(vector<int>& seats) {
       // seats = {0,0,1,0,1,1};
       // seats={0,1};
        int size = seats.size();
        int i = -1;
        int j = -1;
        int d = INT_MIN;
        int k = 0;
        while(k<size and seats[k]==0) {k++;}
        if(k>0) {i=k; d=k;}
        
        for(; k < size; k++) {
           // printf("%d %d %d %d\n", k, i, j, d);
            if(seats[k]==1) {
                if(i==-1) { i =k; }
                else if(j==-1) {
                    j=k; 
                    d=max(d,(j-i)/2);
                }
                else {
                    std::swap(i,j); 
                    j=k; 
                    d=max(d, (j-i)/2);
                }
            }
        }

        k=size-1;
        while(k>=0 and seats[k]==0) {k--;}
        if(k<size-1){d=max(d, size-1-k);}
        
        return d;
    }
};
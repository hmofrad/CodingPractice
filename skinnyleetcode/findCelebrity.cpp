/*
 * https://leetcode.com/problems/find-the-celebrity/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool find_celebrity(int i, int n) {
        for(int j = 0; j < n; j++) {
            if(i==j) continue;
            if(knows(i, j) or not knows(j,i)) return false;
        }
        return true;
    }
    
    int findCelebrity(int n) {
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(knows(c, i)) c=i;
        }
        
        if(find_celebrity(c, n)) { return c; }
        return -1;
    }
    
    int findCelebrity1(int n) {
        for(int i = 0; i < n; i++) {
            if(find_celebrity(i, n)) return i;
        }
        return -1;
    }
};





























class Solution0 {
public:
    int union_find(std::vector<int>& U, int x) {
        return U[x] == -1 ? x : union_find(U, U[x]);
    }
    void union_merge(std::vector<int>& U, int x, int y) {
        int p_x = union_find(U, x);
        int p_y = union_find(U, y);
        if(p_x != p_y) { U[p_x] = p_y; }
    }
    bool union_check(std::vector<int>& U) {
        int n = U.size();
        int c = -1;
        for(int i = 0; i < n; i++) {
            int m = 0;
            for(int j = 0; j < n; j++) {
                if(U[j]==i) { m++; }
            }
            if(m==n-1) { c=i; break; }
        }
        return c;
    }
    int findCelebrity(int n) {
        std::vector<int> U(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(knows(i,j)) {
                    int x = union_find(U, i);
                    int y = union_find(U, j);
                    union_merge(U, x, y);
                    int c = union_check(U);
                    if(c != -1) return c;
                }
            }
        }
        return -1;
    }
};
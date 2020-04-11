/*
 *  https://leetcode.com/problems/circular-permutation-in-binary-representation/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int binary2gray(int num) {
        return num ^ (num >> 1);
    }
    int gray2binary(int num) {
        int mask = num >> 1;
        while(mask) {
            num ^= mask;
            mask >>= 1;
        }
        return(num);
    }
    vector<int> circularPermutation(int n, int start) {
        //int g = binary2gray(n);
        //int b = gray2binary(g);
        //printf("%d %d %d\n", n, g, b);
        int sz = pow(2,n);
        std::vector<int> grays(sz);
        for(int i = 0; i < sz; i++) {
            grays[i] = binary2gray(i);
          //  printf("%d " ,grays[i]);
        }
        //printf("\n");
        
        int pos = 0;
        for(int i = 0; i < sz; i++) {
            if(grays[i] == start) {
                pos = i;
                break;
            }
        }
        //printf("%d\n", pos);
        std::vector<int> ans(sz);
        for(int i = pos, j = 0; i < sz; i++, j++) {
            ans[j] = grays[i];
          //  printf("%d %d %d\n", i, j, ans[j]);
        }
        //printf("%d\n", sz-pos);
        for(int i = 0, j = sz-pos; i < pos; i++, j++) {
            ans[j] = grays[i];
        }
        
        
        return(ans);
    }
};
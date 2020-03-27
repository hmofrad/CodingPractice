/*
 *  https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int sz = S.size();
        if(S.empty() or K > S.size()) return(0);
        int n = 0;
        int i = 0;
        int s = 0;
        while(s <= sz-K) {
         //   printf("%d: ", s);
            bool found = true;
            std::unordered_map<char, bool> u;
            int j;
            for(j = s; j < s+K; j++) {
              //  printf("%c", S[j]);
                char c = S[j];
                if(u.find(c) == u.end()) {
                    u[c]=true;
                }
                else {
                    found = false;
                   // s = j;
                    break;
                }
            }
           // printf(" %d %d %d %d\n", j , K, s, found);
            if(found) {
                n++;
                   
            }
            s++; 
        }
        return(n);
    }
};
/*
 *  Problem: https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    int countLetters1(string S) {
        int k = 0;
        for(int i = 0; i < S.length(); i++) {
            for(int j = i; j < S.length(); j++) {
                if(S[i]==S[j]) {
                    k++;
                }
                else {
                    break;
                }
            }
        }
        return(k);
    }
    
    int countLetters(string S) {
        int k = 1;
        int c = 1;
        for(int i = 1; i < S.length(); i++) {
            if(S[i-1] != S[i]) {
                c = 0;
            }
            c++;
            k += c;
        }
        
        
        return(k);
    }
    
    
};
/*
 *  Problem: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    string generateTheString(int n) {
        std::string out;
        //printf("%d\n",not (n%2));
        if(not (n%2)) {
            out += 'a';
            n--;
        }
        
        for(int i = 0; i < n; i++) {
            out += 'b';
        }
        return(out);   
    }
};
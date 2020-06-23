/*
 * https://leetcode.com/problems/reverse-words-in-a-string-ii/solution/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    void flip(std::vector<char>& s, int left, int right) {
        while(left<right) {std::swap(s[left++], s[right--]);}
    }
    
    void reverseWords(vector<char>& s) {
        
        int len = s.size();
        int j = -1;
        for(int i = 0; i < len; i++) {
            char c = s[i];
            if(c!=' ' and j==-1) {j=i;}
            else if(c==' ' and (j!=-1)){
                flip(s, j, i-1);
                j=-1;
            }
        }
        if(j!=-1) flip(s, j, len-1);
        
        std::reverse(s.begin(), s.end());
    }
};
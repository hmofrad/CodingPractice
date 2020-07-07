/*
 * https://leetcode.com/problems/text-justification/submissions/
 * (c) Mohammad Hasanzadeh Mofrad, 2020
 * (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::string> ans;
        int i = 0;
        int j = 0;
        int len = words.size();
        std::vector<int> spaces(len);
        
        while(i<len) {
            int width = 0;
            int nSpaces = 0;
            while(i<len and (width+words[i].length()) <= maxWidth) { 
                width+=words[i++].length(); 
                if(width+1<=maxWidth) {width++; nSpaces++;}
            }
            nSpaces += maxWidth-width;
            int nWords = (i-j-1) ? i-j-1 : 1;
            bool lastRow = i==len ? true : false;
            if(not lastRow) {
                if(nWords==1) {spaces[j]+=nSpaces;}
                else {
                    int s = nSpaces/nWords;
                    int k = j;
                    for(; k < i-1; k++) {spaces[k]=s; nSpaces-=s;}
                    k = j;
                    while(nSpaces>0) { spaces[k++]++; nSpaces--; }
                }
            }
            else {
                for(int k = j; k < i; k++) { spaces[k]=1; nSpaces--; }
                spaces.back() += nSpaces;
            }

            std::string row;
            for(;j<i; j++) { 
               row += words[j];
               if(spaces[j]) {
                    std::string t(spaces[j], ' ');
                    row += t;
               }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
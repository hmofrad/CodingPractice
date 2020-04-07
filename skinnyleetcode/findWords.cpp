/*
 *  https://leetcode.com/problems/keyboard-row/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    
    vector<string> findWords(vector<string>& words) {
        //                       a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
        std::vector<int> rows = {2,1,1,2,3,2,2,2,3,2,2,2,1,1,3,3,3,3,2,3,3,1,3,1,3,1};
        
        std::vector<string> out;
        for(std::string word: words) {
            bool tf = true;
            int m = word.size();
            int c = word[0];
            int i = (c >= 'a' and c <= 'z') ? c-'a' : c-'A';
            int r = rows[i];
            for(int j = 1; j < m; j++) {
                int c1 = word[j];
                int i1 = (c1 >= 'a' and c1 <= 'z') ? c1-'a' : c1-'A';
                int r1 = rows[i1];
                
                if(r != r1) {tf = false; break;}
                
                r = r1;
            }
            if(tf) out.push_back(word);
        }
        return(out);
    }
};
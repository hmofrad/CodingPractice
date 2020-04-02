/*
 *  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
class Solution {
public:
    
    string removeDuplicates(string S) {
        int m = S.length();
        std::string out;
        int i = 0;
        
        while(i < m) {
            if(i+1<m and S[i] == S[i+1]) i+=2;
            else if(not out.empty() and out.back() == S[i]) {out.pop_back(); i++;}
            else  {out.push_back(S[i]); i++;}
            //else {out.push_back(S[i]); out.push_back(S[i+1]);}
        }
        //if(i == m-1) out.push_back(S[i]);
        //printf("%d %d\n",i, m);
        return(out);
    }
    
    
    string removeDuplicates1(string S) {
        int m = S.length();
        int i = 0;
        int j = -1;
        std::vector<int> indices(m, 1);
        //printf(">>>> %s\n", S.c_str());
        while(i <= m-1) {
            //printf("S[%d]=%c,%c j=%d\n", i, S[i], S[i+1], j);
            if(S[i] == S[i+1]) {
                indices[i] = 0; 
                indices[i+1] = 0; 
                //j=i-1;
                i+=2; 
            }
            else if(j>=0 and S[j] == S[i]) {
                indices[j] = 0;
                j--;
                indices[i] = 0;
                i++;
                /*
                if(j >= 0 and i < m) {
                    while(S[j] == S[i]) {
                        indices[j] = 0;
                        j--;
                        indices[i] = 0;
                        i++;
                    }
                }
                */
            }
            else {
                j=i;
                i++;
            }            
        }
        
        std::string out;
        for(int k = 0; k < m; k++) {
            if(indices[k]) out += S[k];
        }
        //printf("%s\n", out.c_str());
        return(out);
    }
};
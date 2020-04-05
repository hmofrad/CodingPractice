/*
 *  https://leetcode.com/problems/custom-sort-string/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
string customSortString(string S, string T) {
    std::vector<int> T_map(26);
    for(char c: T) {
        T_map[c-'a']++;
    }
    
    std::string O(T.size(),'\0');
    int j = 0;
    for(char c: S) {
        if(c-'a' < 26 and c-'a' >= 0) {
            for(int i = 0; i < T_map[c-'a']; i++) {
                O[j] = c;
                j++;
            }
            T_map[c-'a']=0;
        }
    }
    
    for(int i = 0; i < 26; i++) {
        for(int k = 0; k < T_map[i]; k++) {
            O[j] = 'a' + i;   
            j++;
        }
    }
    
    return(O);
}
    
    
string customSortString1(string S, string T) {
        std::vector<int> S_map(26,26);
        //printf("S=%s T=%s\n", S.c_str(), T.c_str());
        for(int i = 0; i < S.size(); i++) {
        //    printf("[%c %d]\n", S[i], S[i]-'a');
            if(S[i]-'a' < 26 and S[i]-'a' >= 0)
           S_map[S[i]-'a'] = i;
        }
      /*  
        for(int i = 0; i < 26; i++)
            printf("%d ", S_map[i]);
        printf("\n");
    */
int left = 0;
        //int right = T.size()-1;
        int m = T.size();
        int i = 0;
        
        for(int i = 0; i < m-1; i++) {
            for(int j = i+1; j < m; j++) {
                if(S_map[T[j]-'a'] < S_map[T[i]-'a']) std::swap(T[i], T[j]);
            }
        }
        
        return(T);
    }
};

// S is unique

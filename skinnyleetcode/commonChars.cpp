/*
 *  https://leetcode.com/problems/find-common-characters/
 *  g++ -o numUniqueEmails numUniqueEmails.cpp && ./numUniqueEmails
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int m = A.size();
        std::vector<int> letters(26, INT_MAX);
        for(int i = 0; i < m; i++) {
            std::vector<int> t(26);
            for(char& c: A[i]) {
                t[c-'a']++;
            }
            for(int j = 0; j < 26; j++) {
                letters[j] = (t[j] < letters[j]) ? t[j] : letters[j];
            }
        }
        
        std::vector<std::string> out;
        for(int i = 0; i < 26; i++) {
           // printf("%d ", letters[i]);
            if(letters[i]) {
                char c = 'a'+i;
                std::string s(1,c);
                //int t = letters[i]/m;
                //int r = letters[i]%m;
                //out.push_back(s);
               // printf("%c %d\n", c, letters[i]);
                for(int j = 0; j < letters[i]; j++) {
                    //printf("%c\n", c);
                    out.push_back(s);
                }
            }
        }
        return(out);
    }
    
    
    vector<string> commonChars1(vector<string>& A) {
        int m = A.size();
        
        std::vector<int> letters(26);
        for(int i = 0; i < m; i++) {
            for(char& c: A[i]) {
                letters[c-'a']++;
            }
        }
        
        std::vector<std::string> out;
        
        for(int i = 0; i < 26; i++) {
            if(letters[i] >= m) {
                char c = 'a'+i;
                std::string s(1,c);
                int t = letters[i]/m;
                int r = letters[i]%m;
                //out.push_back(s);
                //printf("%c %d\n", c, r);
                for(int j = 0; j < t; j++) {
                    //printf("%c\n", c);
                    out.push_back(s);
                }
            }
        }
        return(out);
    }
};